#ifndef INFO_H
#define INFO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1

#define DATABASE_CREATED -2
#define DATABASE_NOT_CREATED -3

#define DATA_NOT_FOUND -4
#define DATA_FOUND -5

#define SAVE_UNSUCCESSFUL -6
#define SAVE_SUCCESSFUL -7

//structure to access the single linked list for storing file names 
typedef struct file_list
{
	char *fname;
	struct file_list *link;
}File;                         

//structure to access the sub nodes and its data which will be attached to the main node
typedef struct sub_node
{
	int word_c;
	char filename[50];
	struct sub_node *link;
}Sub_t;

//structure to access the main node and its data 
typedef struct main_node
{
	int file_c;
	char word[50];
	Sub_t *sub_link;
	struct main_node *main_link;
}Main_t;

//structure to hold the data to be added to updated database
typedef struct file_data
{
	int index;
	char word[50];
	int file_c;
	char file_name[5][50];
	int word_c[5];
}U_data;

//color function which is used to add respective color to the text
void red();
void green();
void yellow();
void reset();

//function to validate the file and attach it to the linked list if it contains the data 
void file_validation(int argc, char *argv[], File **head);
//function to create the database 
int create_DT(File **head, Main_t *index_arr[]);
//function to display the database details 
void display_DT(Main_t *index_arr[]);
//function to search for the data in the database
int search_DT(Main_t *index_arr[], char *data);
//function to perform the updation operation
int update_DT(Main_t *index_arr[], char *update_f);
//function to save the databse details in a special format in the backup file 
int save_DT(Main_t *index_arr[], char *save_file);
#endif
