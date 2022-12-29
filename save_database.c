#include "info.h"

/*function to backup the data in a specific format*/
int save_DT(Main_t *index_arr[], char *save_file)
{
	FILE *s_fptr = fopen(save_file, "w+");
	if(s_fptr == NULL)
	{
		return SAVE_UNSUCCESSFUL;
	}
	else
	{
		Main_t *m_node;
		Sub_t *s_node;
		int index = 0;
		/*access the list associted with all the index having list associted to it*/
		while(index < 27)
		{
			if(index_arr[index] != NULL)
			{
				m_node = index_arr[index];
				/*if list exists then store all the data associted with that list in the backup file*/
				while(m_node != NULL)
				{
					fprintf(s_fptr,"#;%d;%s;%d", index, m_node -> word, m_node -> file_c);
					s_node = m_node -> sub_link;
					/*to access the sub nodes and the data associated with it. Store it in backup file*/
					while(s_node != NULL)
					{
						fprintf(s_fptr,";%s;%d", s_node -> filename, s_node -> word_c);
						s_node = s_node -> link;
					}
					fprintf(s_fptr,";%c\n",'#');
					m_node = m_node -> main_link;
				}
			}
			index++;
		}
	}
	return SAVE_SUCCESSFUL;
}


