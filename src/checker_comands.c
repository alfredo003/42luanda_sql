#include "42luanda_sql.h"

void checker_comands(char **keywords,char **name_data)
{
	if(strcmp(keywords[0],"create") == 0)
	{
		if(strcmp(keywords[1],"database") == 0)
		{
			create_database(keywords[2]);
		}
		else
			printf("\33[0;41mQuery invalid!\33[0m\n");
	}
	else if(strcmp(keywords[0],"show") == 0)
	{
		if(strcmp(keywords[1],"database") == 0)
		{
			list_database();
		}
		else
			printf("\33[0;41mQuery invalid!\33[0m\n");
	}
	else if(strcmp(keywords[0],"drop") == 0)
	{
		if(strcmp(keywords[1],"database") == 0)
		{
			drop_database(keywords[2]);
		}
		else
			printf("\33[0;41mQuery invalid!\33[0m\n");
	}
	else if (strcmp(keywords[0],"use") == 0)
	{
		if(strcmp(keywords[1],"database") == 0)
		{
			system("clear");
			 *name_data = keywords[2];
		}
		else
			printf("\33[0;41mQuery invalid!\33[0m\n");
	}
	else if (strcmp(keywords[0],"select") == 0)
	{
		if(!name_data)
		{
			if(keywords[1][0] == '*')
			{
				if(keywords[2] == name_data[0])
				{
					printf("funcionou");
				}
			
			}else
			{
				printf("eooooooooooooo");
			}
		}
	}  
	else if (strcmp(keywords[0],"clear") == 0)
	{
		  system("clear");
	}
	else
		printf("\33[0;41mComand invalid!\33[0m\n");
}
