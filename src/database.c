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

void drop_database(const char *name_database)
{
    Node *head = NULL;
    read_file("bin/.config",&head);
    delete_list(&head, name_database);

	char *dir = "bin/database/";
	char *typefile = ".sql";
	char filepath_dir[256];
	char filepath[256];
	
    	snprintf(filepath_dir, sizeof(filepath_dir), "%s%s", dir, name_database);
	snprintf(filepath, sizeof(filepath), "%s%s", filepath_dir,typefile);
	remove(filepath);
     
   FILE * file = fopen("bin/.config", "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    Node *temp = head;
    while (temp != NULL) {
        fprintf(file, "%s\n", temp->data);
        temp = temp->next;
    }

    fclose(file);

    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
 	system("clear");
    printf("\33[0;41mDatabase entry '%s' removed.!\33[0m\n", name_database);
}

void list_database()
{
    Node *head = NULL;
   read_file("bin/.config",&head);
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
