#include "42luanda_sql.h"

FILE *file_config(char *path,char *status)
{
	char *filepath = path;
	FILE *file = fopen(filepath, status);
	    if (file == NULL) {
		printf("Erro ao abrir o arquivo %s\n", filepath);
		exit(1);
	    }
	return file;
}

void read_file(char *path,Node **head)
{
char *filepath = path;
 FILE *file = fopen(filepath, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    char line[MAX_LINE_LENGTH];
    
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        append(head, line);
    }
    fclose(file);
}
