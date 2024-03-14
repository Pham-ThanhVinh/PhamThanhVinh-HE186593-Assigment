#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char c[1000];
	char fileName[100];
	int result;
	int menu_option;
 	printf("        FILE INTERACTION!!!\n");
    printf("------------------------------------------\n\n");

    do{
    	printf("\nMain Menu\n");
    	printf("1. Create a file.\n");
    	printf("2. Add value into a file.\n");
   		printf("3 Read data from file.\n");
    	printf("4. Delete file\n");
    	printf("5. Save and quit.\n");
    	printf(" Please enter an option from the main menu: ");
    	scanf("%d",&menu_option);

    	switch(menu_option){
    	case 1:
        	result = createFile();
        	break;
    	case 2:
        	result =  AddValueToFile();
        	break;
    	case 3:
        	result = ReadValueFromFile();
        	break;
    	case 4:
    	  	result = RemoveFile();
        	break;
    	case 5:
    		printf("Option exit");
        	break;
        default: 
        	printf("Error");
    	}
    }	while(menu_option != 5);
}
// create file func
int createFile() {
	FILE *file;
	char fileName[100];
	printf("Enter a fileName: ");
	scanf("%s", &fileName);
	if((file = fopen(fileName, "w")) == NULL) {
		printf("Cannot create a file");
		return 0;
	}
	printf("Create file successfully\n");
	printf("----------------------------\n");
	fclose(file);
	return 1;
}
// write to file func
int AddValueToFile() {
	FILE *file;
	char fileName[100];
	char content[100];
	printf("Enter a fileName: ");
	scanf("%s", &fileName);
	if((file = fopen(fileName, "r")) == NULL) {
		printf("Cannot open %c file to write", fileName);
		return 0;
	} else {
		file = fopen(fileName, "a");
		printf("Enter content to append to the file:\n");
    	scanf(" %[^\n]", content);

    	// Write content to the file
    	fprintf(file, "%s\n", content);
	}
	fclose(file);
	printf("Add vlaue into file successfully\n");
	printf("----------------------------\n");

	return 1;
}

// read file func
int ReadValueFromFile() {
	FILE *file;
	char fileName[100];
	char line[100];

	printf("Enter a fileName: ");
	scanf("%s", &fileName);
	if((file = fopen(fileName, "r")) == NULL) {
		printf("Cannot open %s file for reading\n", fileName);
		return 0;
	} else {
		printf("\n----------------------------------\n");
		printf("Contents of the file %s:\n", fileName);
    	while (fgets(line, sizeof(line), file) != NULL) {
        	printf("%s", line);
    	}
    	printf("\n----------------------------------\n");
	}
	fclose(file);
	printf("Read vlaue from %s file successfully\n", fileName);
	printf("----------------------------\n");

	return 1;
}
// delete file func
int RemoveFile() {
	FILE *file;
	char fileName[100];

	printf("Enter a fileName: ");
	scanf("%s", &fileName);
	printf("\n----------------------------------\n");
	if (remove(fileName) == 0) {
        	printf("File %s removed successfully.\n", fileName);
    	} else {
        printf("Unable to remove the file %s.\n", fileName);
        	return 0;
    	}
		printf("\n----------------------------------\n");
	printf("----------------------------\n");
	return 1;
}

