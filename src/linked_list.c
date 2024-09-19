#include "42luanda_sql.h"

Node* create_node(char *data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    strncpy(new_node->data, data, MAX_LINE_LENGTH);
    new_node->next = NULL;
    return new_node;
}
 
void append(Node **head, char *data)
{
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

void delete_list(Node **head,const char *data_to_delete)
{
	Node *temp = *head;
    Node *prev = NULL;

    while (temp != NULL && strcmp(temp->data, data_to_delete) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // Data not found

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}


