#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char letter;
    struct Node *next;
};

//prototypes
void print (struct Node *head);
void insert (struct Node *head, char letter);

int main() {
    struct Node *head = NULL;

    insert(head, 'a');

    printf("%c", head->letter);





    return 0;
}

//prints all of the nodes in order
void print (struct Node *head){
    struct Node currNode = *head->next;
    while (currNode.next != NULL){
        printf("%c ", currNode.letter);
        currNode = *currNode.next;
    }

    printf("\n");
}

void insert (struct Node *head, char letter){
    if (head == NULL){
        struct Node *node =(struct Node*)malloc(sizeof(struct Node));
        node->next = NULL;
        node->letter = &letter;
        head = node;
    }

}