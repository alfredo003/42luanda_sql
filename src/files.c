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
