#include "42luanda_sql.h"


void register_database(char *name_database)
{
	FILE *file = file_config("bin/.config","a");
  	fprintf(file, "%s\n", name_database);
    	fclose(file);
}
void create_database(char *name_database)
{
	char *dir = "bin/database/";
	char *typefile = ".sql";
	char filepath_dir[256];
	char filepath[256];
	
    	snprintf(filepath_dir, sizeof(filepath_dir), "%s%s", dir, name_database);
	snprintf(filepath, sizeof(filepath), "%s%s", filepath_dir,typefile);
	  
	FILE *check_file = fopen(filepath, "r");
	  if (check_file != NULL) {
		fclose(check_file);
		printf("\33[0;41mError: Database %s already exist!\33[0m\n", name_database);
		return;
	    }
	    
	FILE *file = fopen(filepath,"w");
	if (file == NULL) {
         	printf("Erro ao abrir o arquivo");
         	return;
    	}

	
    fprintf(file, "CREATE DATABASE %s;\n",name_database);
    fclose(file);
    
    register_database(name_database);
    system("clear");
    printf("\33[0;42mDatabase - %s - created with success!\33[0m\n",name_database);
	
}

void drop_database(char *name_database)
{
    Node *temp = head;
    while (temp != NULL)
    {
    	 
        printf("%s",temp->data);
        temp = temp->next;
    }
    
    printf("\n%s\n",name_database);
	/*char *dir = "bin/database/";
	char *typefile = ".sql";
	char filepath_dir[256];
	char filepath[256];
	
    	snprintf(filepath_dir, sizeof(filepath_dir), "%s%s", dir, name_database);
	snprintf(filepath, sizeof(filepath), "%s%s", filepath_dir,typefile);
	
	if(remove(filepath) == 0)
	{
		
	  	system("clear");
		printf("\33[0;42mdatabase %s drop with success!.\33[0m\n", name_database);
  	} else {
  	  	system("clear");
		printf("Erro : database not drop!.\n");
        }*/
	
	
}

void list_database()
{
   FILE * file = file_config("bin/.config","r");
     Node *head = NULL;
    char line[MAX_LINE_LENGTH];

   
    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line, "\n")] = 0;
        append(&head, line);
    }

    fclose(file);
 
    Node *temp = head;
     system("clear");
     	printf("+-----------------------+\n");
     	printf("|\tDATABASE\t|\n");
     	printf("+-----------------------+\n");
    while (temp != NULL)
    {
        printf("|\t%s\t\t|\n", temp->data);
        temp = temp->next;
    }
      printf("+-----------------------+\n");

    temp = head;
    while (temp != NULL)
    {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
}
