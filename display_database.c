#include "info.h"
/*Function to display the contents stored in the database*/
void display_DT(Main_t *index_arr[])
{
	Main_t *m_temp;
	Sub_t *s_temp;
	int index = 0;
	printf("%-6s%-20s%-15s%-20s%-10s\n","Index ","Word ","Filecount ","Filename ","Word_Count ");
	
	/*run the loop till we scan through all the lists at the respective indexes*/
	while(index < 27)
	{
		if(index_arr[index] != NULL)
		{
		    m_temp = index_arr[index];
			if(m_temp != NULL)
			{
				/*if value at that index is not NULL then scan through the list associated to it*/
				while(m_temp != NULL)
				{
					printf("%-6d",index);
					printf("%-20s", m_temp -> word);
					printf("%-2d%c%-7s%-5s", m_temp -> file_c,' ',"file(s)"," ");
					s_temp = m_temp -> sub_link;

					/*print the details of the sub nodes associted with the words*/
					while(s_temp != NULL)
					{
						printf("%-20s", s_temp -> filename);
						printf("%-10d", s_temp -> word_c);
						printf("%c",' ');
						s_temp = s_temp -> link;
					}
					m_temp = m_temp -> main_link;
					printf("\n");
				}
			}
		}
		index++;
	}
}

