#include"info.h"

//function to create new sub nodes and make connection with the previous sub nodes
void add_subnode(Sub_t **s_node, char *filename, int word_c)
{
	//create a new sub nodes 
	Sub_t *new_s = malloc(sizeof(Sub_t));
    //update the data of the new sub nodes 
	new_s -> word_c = word_c;
	strcpy(new_s -> filename, filename); 
    //establish the connection of new node with previous node 
	Sub_t *s_head = *s_node;
	while(s_head -> link != NULL)
	{
		s_head = s_head -> link;
	}
	s_head -> link = new_s;
}

//function to create the databse and to store the data in it 
void update_data(Main_t **m_head, U_data *u_info, int f_j)
{
	int index = 0;
	Main_t *main_n = malloc(sizeof(Main_t)); 
	
	//if main node to be added at the index is first node then update head to hold first main node address
	if(*m_head == NULL)
	{
		*m_head = main_n;
	}
	else                                     //scan through the list and serach for last node 
	{
		Main_t *temp_m = *m_head;
		while(temp_m -> main_link != NULL)
		{
			temp_m = temp_m -> main_link;
		}
		temp_m -> main_link = main_n;         //update the last node link with the new node to be added
	}
    
    //update the data of the main node 
	main_n -> file_c = u_info -> file_c;
	strcpy(main_n -> word, u_info -> word);
	main_n -> main_link = NULL;
    
    //update the data of the sub nodes and make appropriate connections 
	Sub_t *sub_n = malloc(sizeof(Sub_t));
	sub_n -> word_c = u_info -> word_c[index];
	strcpy(sub_n -> filename, u_info -> file_name[index]);
	main_n -> sub_link = sub_n;

	//if more than one file has the same data then create new nodes and make connections with the previous sub nodes 
	while(++index < f_j)
	{
		add_subnode(&sub_n, u_info -> file_name[index], u_info -> word_c[index]);
	}
}

/*function to update the file data into the databse*/
int update_DT(Main_t *index_arr[], char *update_f)
{
	U_data u_info; 
	FILE *u_fptr = fopen(update_f, "r");
	if(u_fptr == NULL)
		return FAILURE;
	else
	{
		char str[100];
		char ch;
		int i = 0, j = 0;
		
		/*run the loop till we scan through the content in the file */
		while((ch = fgetc(u_fptr)) > 0)
		{
			//update the characters in the string so that we can read the data line by line from the file 
			if(ch != '\n')
			{
				str[i++] = ch;
			}
			else
			{
				str[i] = '\0';
				int count = 0, w_j = 0, f_j = 0, prev_c = 0;
				char *p_data = strtok(str,";");
				
				//run the loop till we access all the data present in thee line stored in str after we read each line 
				while(p_data != NULL)
				{
					if(strcmp(p_data,"#") != 0)
					{
						count++;
						
						//if the count is > 5 then it means that word i s present in more than one file and to store the detail we need reset count 
						if(count > 5)
						{
							prev_c = count;
							if(count % 2 == 0)
								count = 4;               //for file name 
							else
								count = 5;               //for word count 
						}
						
						//use the count to update the data in the respective field
						switch(count)
						{
							case 1 : u_info.index = atoi(p_data);
									 break;
							case 2 : strcpy(u_info.word, p_data);
									 break;
							case 3 : u_info.file_c = atoi(p_data);
									 break;
							case 4 : 
									 {
										 strcpy(u_info.file_name[f_j], p_data);
										 f_j++;
									 }
									 break;
							case 5 : {
										 u_info.word_c[w_j] = atoi(p_data);
										 w_j++;
									 }
									 break;
						}
					}
					p_data = strtok(NULL,";");
					if(count > 5)
						count = prev_c;
				}	
				update_data(&index_arr[u_info.index], &u_info, f_j); //call the function to store the data in the database for that string 
				i = 0;
			}
		}
	}
	return SUCCESS;
}

