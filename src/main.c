#include "42luanda_sql.h"

char *name_data = NULL;

char **verify_keyword(char *query)
{
	toLowerCase(query);
	return (ft_split(query));
}

int main(void)
{
	char query[100];
	char **keywords;
	system("clear");	
	while(1)
	{
	menu(name_data);

		if(fgets(query, sizeof(query),stdin) != NULL)
		{
			size_t len = strlen(query);
			if(len > 0 && query[len-1] == '\n')
			{
				query[len -1] = '\0';
			}
			
			keywords = verify_keyword(query);

			checker_comands(keywords,&name_data);
		}
		else
		{
			printf("Erro ao ler a Entrada.\n");
		}
	}
	
	return (0);
}
