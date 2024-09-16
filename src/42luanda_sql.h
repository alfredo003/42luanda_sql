#ifndef SGDB_H
#define SGDB_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

typedef struct Node {
    char data[MAX_LINE_LENGTH];
    struct Node *next;
} Node;

void menu();
void menu_database(char *name_database);
void create_database(char *name_database);
void drop_database(char *name_database);
void checker_comands(char **keywords);
void list_database();
void toLowerCase(char *str);
char **ft_split(char *str);
char *ft_strncpy(char *s1,char *s2 , int size);
char *ft_strcat(char *dest, char *src);
Node* create_node(char *data);
void append(Node **head, char *data);
#endif
