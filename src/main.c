#include "42luanda_sql.h"

char **verify_keyword(char *query)
{
	toLowerCase(query);
	return (ft_split(query));
}
void create_database(char *name_database)
{
	char *dir = "bin/database/";
	char *ss = ".sql";
	 char filepath_dir[256];
	  char filepath[256];
    	  snprintf(filepath_dir, sizeof(filepath_dir), "%s%s", dir, name_database);
	  snprintf(filepath, sizeof(filepath), "%s%s", filepath_dir,ss);
	  
	FILE *file = fopen(filepath,"w");

	if (file == NULL) {
         printf("Erro ao abrir o arquivo");
    	}

    fprintf(file, "CREATE DATABASE %s;\n",name_database);
	
}
int main(void)
{
	char query[100];
	char **keywords;
	menu();

	if(fgets(query, sizeof(query),stdin) != NULL)
	{
		size_t len = strlen(query);
		if(len > 0 && query[len-1] == '\n')
		{
			query[len -1] = '\0';
		}
		
		keywords = verify_keyword(query);

		if(strcmp(keywords[0],"create") == 0)
		{
			if(strcmp(keywords[1],"database") == 0)
			{
				create_database(keywords[2]);
			}
			else if (strcmp(keywords[0],"select") == 0)
			{
				
			}
			else
				printf("\33[0;41mQuery invalid!");
		}
		else if (strcmp(keywords[0],"select") == 0)
		{
		
		}
		else
			printf("\33[0;41mComand invalid!");
	}
	else
	{
		printf("Erro ao ler a Entrada.\n");
	}
	
	return (0);
}
