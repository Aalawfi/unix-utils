#include <stdio.h> 
/**
 This utility search (case-sensitive) for a keyword in a given file(s). 
 If the keyword was found in the line, it will print out that line. 
 **/


// Given a base address for a string, find its length
size_t findWordLength(char * aWord){ 	
	size_t count = 0;
	
	for(size_t i = 0; aWord[i] != '\0'; i++){
		count++;
	}

	return count;
}

// given a : line, its length, keyword, its length
//  return 1 or 0 if a keyword exists in that line 
int checkForKeyword(char * line, size_t lineLength, 
		    char * keyword, size_t keywordLength){
	
	size_t i, j;
	
	for (i = 0; i < lineLength - keywordLength; i++) {
		for (j = i; j < i + keywordLength; j++) {
			
			if (line[j] != keyword[j - i]){
				break;
			}
		  }
		if (j == i + keywordLength){
			return 1; 
		}
	}
        return 0;

}

// Opens a file, read it line by line, and print out the line if a given keyword
// exists in it
int searchInFile(FILE * searchFile, char * keyword, size_t keywordLength){

	// check if search file exists
	if(searchFile == NULL){
		printf("Couldn't find file \n");
		return -1;
	}

	// read each line and store in lineptr
	// check `man getline` for more info
	char * lineptr = NULL; 
	size_t n = 0;
	ssize_t readChars; 
	while((readChars = getline(&lineptr, &n, searchFile)) != -1){

		// find length of the line 
		size_t lineLength = findWordLength(lineptr);

		// print out the line if the keyword exists
		if(checkForKeyword(lineptr, lineLength, keyword, keywordLength) == 1){
			printf("%s\n", lineptr);
		}
 
	} 
	return 0;
}


int main(int argc, char *argv[]){

	// No input at all
	if(argc <= 1){
		printf("No input was given\n");
		return -1;
	}

	size_t keywordLength = findWordLength(argv[1]);
	
	// search term given but no files, 
	if(argc == 2){
	
	char userInput[40];
	fscanf(stdin, "%s", userInput);

	// Apply searchInFile on stidn file
	searchInFile(stdin, argv[1], keywordLength);
	fclose(stdin);
	return 0;	
	}

	// if file name was given, open stream for each file and apply searchInFile routine
	if(argc > 2) {
		for(short int i = 2; i < argc; i++){
			FILE * searchFile = fopen(argv[i], "r");
			searchInFile(searchFile, argv[1], keywordLength);
			fclose(searchFile);
		}
	}
	return 0;
}
