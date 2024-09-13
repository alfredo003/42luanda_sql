#ifndef SGDB_H
#define SGDB_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>


void menu();
void toLowerCase(char *str);
char **ft_split(char *str);
char *ft_strncpy(char *s1,char *s2 , int size);
char *ft_strcat(char *dest, char *src);
#endif
