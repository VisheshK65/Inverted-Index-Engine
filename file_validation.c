#include "info.h"

/*function to add the file to the linked list if not already been added to it*/
int append_file(File **head, char *file)
{
	File *new_f = (File *)malloc(sizeof(File));
	if(new_f == NULL)
	{
		printf("!! File not added to the list !!\n");
		return FAILURE;
	}
	new_f -> fname = file;
	new_f -> link = NULL;

	/*if the list is empty then attach it to the head*/
	if(*head == NULL)
	{
		*head = new_f;
		return SUCCESS;
	}

	/*if the list is not empty, then attach it to the last node*/
	File *temp = *head;
	File *prev;
	while(temp != NULL)
	{
		prev = temp;
		/*if the filename is already added to the node, then print the error message*/
		if(strcmp(temp -> fname, file) == 0)
		{
			red();
			printf("ERROR      : ");
			reset();
			printf("%s already present in the list. Hence no need to add it\n", temp -> fname);
			return FAILURE;
		}
		temp = temp -> link;
	}
	/*else attach it to the last node in the list*/
	prev -> link = new_f;
	return SUCCESS;
}

/*function to check if the file is containing any data, then add it to the list */
void file_validation(int argc, char *argv[], File **head)
{
	int index = 1;
	/*run the loop till we read through all the files been passed at command line*/
	while(index < argc)
	{
		FILE *fptr = fopen(argv[index], "r");
		if(fptr == NULL)
		{
			red();
			printf("ERROR      : ");
			reset();
			printf("%s file is been not created\n", argv[index]);
			index++;
			continue;
		}	
		fseek(fptr, -1, SEEK_END);
		if(ftell(fptr) != 0)
		{
			/* If the file is containing any data then add it to the list*/
			if(append_file(head, argv[index]) == SUCCESS)
			{
				green();
				printf("SUCCESSFUL : ");
				reset();
				printf("inserting %s into linked list\n", argv[index]);
			}
		}
		else  //else print the error message 
		{
			red();
			printf("ERROR      : ");
			reset();
			printf("%s is empty file. Hence we are not adding it to the list\n", argv[index]);
		}
		index++;
		fclose(fptr);
	}
}


