/**
 * Given a file name, read and return the content of that file 
 * If no file is given (len of argv is 1, then do nothing)
 *	
 *	To open a file use a unix system call fopen
 *	read line by line and save in memory 
 *	close file 
 *	return the saved copy in memory
 * **/
#include <stdio.h> 

int main(int argc, char *argv[]){
	printf("\n");

	// Check if input is given, do nothing if not
        if(argc <= 1)
	{
		printf("No input was given\n");
		return -1;
	}
	
	// Open the file in question
	FILE * obj_file = fopen(argv[1], "r");
	if(obj_file == NULL)
	{
		printf("couldn't find the file\n");
		return -1;
	}	

	// Read content until no new line
	char *line = NULL; 
	size_t len = 0; 
	ssize_t nread; 
	while((nread = getline(&line, &len, obj_file)) != -1){
		printf("%s", line);
	}

	// close file and exit.
	fclose(obj_file);
	printf("\n");
	return 0;
}
