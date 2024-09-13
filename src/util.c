#include "42luanda_sql.h"


void menu()
{
	printf("+==========================+\n");
	printf("\t42Luanda SQL:\n");
	printf("+==========================+\n");
	
	
}
void toLowerCase(char *str) {
    while (*str) {          
        *str = tolower((unsigned char)*str); 
        str++;            
    }
}

char *ft_strncpy(char *s1,char *s2 , int size)
{
	int i =-1;
	while(++i < size && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

char **ft_split(char *str)
{
	int i=0;
	int len=0;
	int k =0;
    int j = 0;
	while(str[i])
	{
		while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if(str[i])
			len++;
		while(str[i] && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;		
	}
	
	char **res = (char **)malloc(sizeof(char *) * len + 1);
	i =0;
	
	while(str[i])
	{
		while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while(str[i] && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if(i > j)
		{
			res[k] = (char *)malloc(sizeof(char)* (i-j)+1);
			ft_strncpy(res[k++],&str[j],(i-j));
		}
	}
	
	res[k] = '\0';
	return (res);
}

char *ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	
	dest[i + j] = '\0';
	return (dest);
}

