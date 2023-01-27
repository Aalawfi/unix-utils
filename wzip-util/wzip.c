#include <stdio.h>
#include <string.h>


// returns length of a string
size_t  getStrLen(char * str){
	size_t count = 0;
	for(size_t i = 0; str[i] != '\0'; i++){
		count++;
	}
	return count;
}


int main(int argc, char * argv[]){

	// Does nothing if no arguments given	
	if(argc < 1){

		printf("No input was given \n");
		return 0;
	}
	
	// Opens input file stream 
	FILE * fileToZip = fopen(argv[1], "r");
	if(fileToZip == NULL)
	{
		printf("Couldn't find the file\n");
		return -1;
	}
	
	// Create a new file (zipping destination)
	char zipExtension[4] = ".zip"; 

	// TODO: This will replace argv in-place, is this bad practice?
	// create copy of argv instead?
	strcat(argv[1], zipExtension);
	FILE * newFile = fopen(argv[1], "wb");
	
	// Read line. Check 'man getline' for info
	char * lineptr = NULL;
	size_t n; 
	size_t charsRead; 	
	while((charsRead = getline(&lineptr, &n, fileToZip)) != -1 ){
		
		// Each character exists at least once
		int CharCount = 1;
		for(size_t i = 0; i < charsRead - 1; i++){
			
			// if the current char and the one after it are equal, 
			// increment count
			if(lineptr[i] == lineptr[i + 1])
			{ 
				CharCount++;
			}
			else {
				// Write the count in a char representation
				fprintf(newFile, "%d", CharCount);
				fwrite(&lineptr[i], sizeof(char), 1, newFile);
				CharCount = 1; // reset count
			}
		}
		
	}

	fclose(newFile);
	return 0;

}
