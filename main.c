/*
Name          : VISHESH K
Date          : 03-12-2022
Documentation : INVERTED SERACH
Sample Execution :

SUCCESSFUL : inserting f1.txt into linked list
SUCCESSFUL : inserting f2.txt into linked list
ERROR      : f3.txt is empty file. Hence we are not adding it to the list
ERROR      : f4.txt file is been not created
--------------------------------------------------
1. Create Database
2. Display Database
3. Search
4. Update Database
5. Save
6. Exit
Enter Your Choice:
1
DATABASE CREATION SUCCESSFUL
Do you want to continue [y/n] : y
--------------------------------------------------
1. Create Database
2. Display Database
3. Search
4. Update Database
5. Save
6. Exit
Enter Your Choice:
2
Index Word                Filecount      Filename            Word_Count
0     are                 1  file(s)     f1.txt              1
0     am                  1  file(s)     f2.txt              1
4     Embedded            1  file(s)     f1.txt              1
4     Emertxe             1  file(s)     f2.txt              1
8     in                  1  file(s)     f1.txt              1
8     I                   1  file(s)     f2.txt              1
12    my                  1  file(s)     f2.txt              1
18    System              1  file(s)     f1.txt              1
19    training            2  file(s)     f1.txt              1          f2.txt              1
20    undergoing          2  file(s)     f1.txt              1          f2.txt              1
22    Where               1  file(s)     f1.txt              1
24    you                 1  file(s)     f1.txt              1
26    @                   2  file(s)     f1.txt              1          f2.txt              1
26    ?                   1  file(s)     f1.txt              1
26    .                   1  file(s)     f2.txt              1
Do you want to continue [y/n] : y
--------------------------------------------------
1. Create Database
2. Display Database
3. Search
4. Update Database
5. Save
6. Exit
Enter Your Choice:
3
Enter the data to be searched for : training
Word : training is found in the database. It is present in 2 file(s).
Present in f1.txt -> 1 time(s)
Present in f2.txt -> 1 time(s)
Do you want to continue [y/n] : y
--------------------------------------------------
1. Create Database
2. Display Database
3. Search
4. Update Database
5. Save
6. Exit
Enter Your Choice:
3
Enter the data to be searched for : hello
hello is not present the database
Do you want to continue [y/n] : y
--------------------------------------------------
1. Create Database
2. Display Database
3. Search
4. Update Database
5. Save
6. Exit
Enter Your Choice:
5
Enter the file name where you want the data to be stored : backup.txt
Do you want to continue [y/n] : y
--------------------------------------------------
1. Create Database
2. Display Database
3. Search
4. Update Database
5. Save
6. Exit
Enter Your Choice:
6

SUCCESSFUL : inserting f1.txt into linked list
SUCCESSFUL : inserting f2.txt into linked list
ERROR      : f3.txt is empty file. Hence we are not adding it to the list
ERROR      : f4.txt file is been not created
--------------------------------------------------
1. Create Database
2. Display Database
3. Search
4. Update Database
5. Save
6. Exit
Enter Your Choice: 
4
Enter the file whose data is to be stored in databse : backup.txt
Do you want to continue [y/n] : y
--------------------------------------------------
1. Create Database
2. Display Database
3. Search
4. Update Database
5. Save
6. Exit
Enter Your Choice: 
2
Index Word                Filecount      Filename            Word_Count 
0     are                 1  file(s)     f1.txt              1          
0     am                  1  file(s)     f2.txt              1          
4     Embedded            1  file(s)     f1.txt              1          
4     Emertxe             1  file(s)     f2.txt              1          
8     in                  1  file(s)     f1.txt              1          
8     I                   1  file(s)     f2.txt              1          
12    my                  1  file(s)     f2.txt              1          
18    System              1  file(s)     f1.txt              1          
19    training            2  file(s)     f1.txt              1          f2.txt              1          
20    undergoing          2  file(s)     f1.txt              1          f2.txt              1          
22    Where               1  file(s)     f1.txt              1          
24    you                 1  file(s)     f1.txt              1          
26    @                   2  file(s)     f1.txt              1          f2.txt              1          
26    ?                   1  file(s)     f1.txt              1          
26    .                   1  file(s)     f2.txt              1          
Do you want to continue [y/n] : n
*/

#include "info.h"

int main(int argc, char *argv[])
{
	File *head = NULL;

	//check if the required no of arguements is been passed at command line
	if(argc > 1)
	{
		//call the function to validate the files been passed and add it to the list 
		file_validation(argc, argv, &head);
		int option;
		char choice = 'y';
		Main_t *index_arr[27] = { NULL };	

		//flag variable used to check if the database is been craeted or not 
		int flag = 0, flag1 = 0;

		//run the loop to select which operation is to be performed 
		while(choice == 'y')
		{
			printf("--------------------------------------------------\n");
			printf("1. Create Database\n2. Display Database\n3. Search\n4. Update Database\n5. Save\n6. Exit\n");
			printf("Enter Your Choice: \n");
			scanf("%d", &option);

			//based on the choice made perform the required operation
			switch(option)
			{
				//option to perform the create databse operation
				case 1 : 
					{
						if(create_DT(&head, index_arr) == DATABASE_CREATED)
						{
							flag = 1;
							green();
							printf("DATABASE CREATION SUCCESSFUL\n");
							reset();
						}
						else if(create_DT(&head, index_arr) == DATABASE_NOT_CREATED)
						{
							red();
							printf("SORRY ! FAILED TO CREATE THE DATABASE\n");
							reset();
						}
						else if(create_DT(&head, index_arr) == FAILURE)
						{
							red();
							printf("COULDN'T OPEN THE FILE\n");
							reset();
						}
					}
					break;

					//option to display the database content 
				case 2 : 
					{
						//if the database is created then continue with the display function
						if(flag == 1 || flag1 == 1)
							display_DT(index_arr);
						else
						{
							red();
							printf("ERROR : DATABASE IS NOT BEEN CREATED \n");
							reset();
						}
					}
					break;

					//option to perform the search operation to search if the given data is present in the database
				case 3 :
					{
						//if the database is created then continue with the serach operation
						if(flag == 1 || flag1 == 1)
						{
							char data[20];
							printf("Enter the data to be searched for : ");
							scanf("%s", data);
							if(search_DT(index_arr, data) == DATA_NOT_FOUND)
							{
								printf("%s is not present the database\n", data);
							}
						}
						else
						{
							red();
							printf("ERROR : DATABASE IS NOT BEEN CREATED \n");
							reset();
						}
					}
					break;
                   //option to update the result data in a backup file  
				case 4 :
					{
						//this function is been called to stroe the result in a backup file passed by the user 
						char updated_file[50];
						printf("Enter the file whose data is to be stored in databse : ");
						scanf("%s", updated_file);
						if(update_DT(index_arr, updated_file) == FAILURE)
						{
							red();
							printf("UPDATION OPERATION FAILED\n");
							reset();
						}
						flag1 = 1;
					}
                    break;
					//option to create a backup of the database 
				case 5 :
					{
						//if the databse is created then continue with the save operation
						if(flag)
						{
							char file_name[50];
							printf("Enter the file name where you want the data to be stored : ");
							scanf("%s", file_name);
							if(save_DT(index_arr, file_name) == SAVE_UNSUCCESSFUL)
							{
								red();
								printf("SAVE OPERATION UNSUCCESSFUL\n");
								reset();
							}
						}
						else
						{
							red();
							printf("ERROR : DATABASE IS NOT BEEN CREATED\n");
							reset();
						}
					}
					break;

				case 6 : return SUCCESS;

				default : printf("!! ENTER A VALID OPTION !!\n");
			}
			yellow();
			printf("Do you want to continue [y/n] : ");
			scanf(" %c", &choice);
			reset();
		}
	}
	else         //run this block if the required command line arguement is not been passed 
	{
		red();
		printf("ERROR : !! INVALID ARGUEMENT !!\n");
		reset();
		green();
		printf("USAGE : ");
		reset();
		printf("./a.out file1.txt file2.txt ....\n");
	}
	return 0;
}


