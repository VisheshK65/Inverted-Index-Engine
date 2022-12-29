#include "info.h"

/*function to add the node with the associated data at the repsective position*/
int insert_main_node(Main_t **m_head, char *t_word, char *filename)
{
	/*if the link at the index position is NULL then create a new main link and attach it to the pointer to which index is pointing to*/
	if(*m_head == NULL)
	{
		Main_t *new_main = malloc(sizeof(Main_t));
		*m_head = new_main;
        /*add data to the main node*/
		new_main -> file_c = 1;
		strcpy(new_main -> word, t_word);
		new_main -> main_link = NULL;
        /*add data to the sub node and attach it to main node if the sub node with same filename is not been created prior*/
		Sub_t *new_sub = malloc(sizeof(Sub_t));
		new_sub -> word_c = 1;
		strcpy(new_sub -> filename, filename);
		new_sub -> link = NULL;
		new_main -> sub_link = new_sub;
	}
	else
	{
		/*if the link is not NULL then add it to the last node in the list */
		Main_t *temp_m = *m_head;
		Main_t *prev;
		/*check if the word is already added to one of the list*/
		while(temp_m != NULL)
		{
			prev = temp_m;
			if(strcmp(temp_m -> word, t_word) == 0)
			{
				Sub_t *temp_s = (temp_m) -> sub_link;
				Sub_t *prev_s;
				while(temp_s != NULL)
				{
					prev_s = temp_s;
					/*check if the word is matching to any node word*/
					if(strcmp(temp_s -> filename, filename) == 0)
					{
						temp_s -> word_c += 1;
						return SUCCESS;
					}
					temp_s = temp_s -> link;
				}
				/*if word matches but the file is differs then add a new sub node*/
				Sub_t *new_s = malloc(sizeof(Sub_t));
				new_s -> word_c = 1;
				strcpy(new_s -> filename, filename);
				new_s -> link = NULL;
				prev_s -> link = new_s;
				temp_m -> file_c += 1;
				return SUCCESS;
			}
			temp_m = temp_m -> main_link;
		}
       
       	/*if word is not added to the list then create a new node and sub node and attach it respectively*/
		Main_t *new_m = malloc(sizeof(Main_t));
		new_m -> file_c = 1;
		strcpy(new_m -> word, t_word);
		new_m -> main_link = NULL;
		new_m -> sub_link = NULL;
		prev -> main_link = new_m;

		Sub_t *new_sub = malloc(sizeof(Sub_t));
		new_sub -> word_c = 1;
		strcpy(new_sub -> filename, filename);
		new_sub -> link = NULL;
		new_m -> sub_link = new_sub;
	}
	return SUCCESS;
}

/*function to create a new databse by storing the content in the files been passed at command line*/ 
int create_DT(File **head, Main_t *index_arr[])
{
	if(*head == NULL)
		return FAILURE;

	File *temp = *head;
	/*access the filenames present in the linked list*/
	while(temp != NULL)
	{
		FILE *fptr = fopen(temp -> fname, "r");
		if(fptr == NULL)
		{
			return FAILURE;
		}
		fseek(fptr, 0, SEEK_SET);

		char t_word[50];
		/*access the words one by one present in the file*/
		while(fscanf(fptr, "%s", t_word) > 0)
		{
			int index;
			/*if word begins with any alphabet then find the index else store 26*/ 
			if((t_word[0] >= 65 && t_word[0] <= 90) || (t_word[0] >= 97 && t_word[0] <= 122))
				index = ((toupper(t_word[0]) - 'A') % 26);
			else
				index = 26;
			/*if data access from the file results failure then returns FAILURE*/
			if(insert_main_node(&index_arr[index], t_word, temp -> fname) != SUCCESS)
			{
				return DATABASE_NOT_CREATED;
			}
		}
		temp = temp -> link;
		fclose(fptr);
	}
	return DATABASE_CREATED;
}


