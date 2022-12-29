#include "info.h"

int search_DT(Main_t *index_arr[], char *data)
{
	Main_t *m_node;
	Sub_t *s_node;
	int index;
	/*check for the index at which the data could be found*/
    if((data[0] >= 65 && data[0] <= 90) || (data[0] >= 97 && data[0] <= 122))
        index = ((toupper(data[0]) - 'A') % 26);
	else
		index = 26;
	/*check if their is any list attached to that index */
	if(index_arr[index] != NULL)
	{
		m_node = index_arr[index];
		/*run the loop till we search for the element in the main node linked list*/
		while(m_node != NULL)
		{
			/*if word matches then print the details respectively*/
			if(strcmp(m_node -> word, data) == 0)
			{
				printf("Word : %s is found in the database. It is present in %d file(s).\n", data, m_node -> file_c);
				s_node = m_node -> sub_link;
				
				/*access the sub nodes and print the details*/
				while(s_node != NULL)
				{
					printf("Present in %s -> %d time(s)\n", s_node -> filename, s_node -> word_c);
					s_node = s_node -> link;
				}
				return DATA_FOUND;
			}
			m_node = m_node -> main_link;
		}
	}
	return DATA_NOT_FOUND;
}

		



