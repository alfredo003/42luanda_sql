#include "42luanda_sql.h"

void register_database(char *name_database)
{
	char filepath[256] = "bin/config.txt";
	FILE *file = fopen(filepath, "a");
	    if (file == NULL) {
		printf("Erro ao abrir o arquivo %s\n", filepath);
		return;
	    }

  	  fprintf(file, "%s.sql\n", name_database);
    
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
		printf("\33[0;41mError: Database %s already exist!\n", name_database);
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


Node* create_node(char *data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    strncpy(new_node->data, data, MAX_LINE_LENGTH);
    new_node->next = NULL;
    return new_node;
}
 
void append(Node **head, char *data) {
    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void list_database() {
    char filepath[256] = "bin/config.txt";
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        printf("\33[0;41mErro: Não foi possível abrir o arquivo %s\n", filepath);
        return;
    }

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
    while (temp != NULL) {
        printf("|\t%s\t|\n", temp->data);
        temp = temp->next;
    }
      printf("+-----------------------+\n");

    temp = head;
    while (temp != NULL) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
}
