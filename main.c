#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char letter;
    struct Node *next;
};

//prototypes
void print ();
void insert (char letter);

struct Node *head = NULL;
struct Node *tail = NULL;

int main() {
    insert('z');
    insert('x');
    insert('a');
    insert('d');
    insert('c');
    print();

    return 0;
}

//prints all nodes. actually works.
void print (){
    struct Node *currNode = head;
    while (currNode != NULL){
        printf("%c ", currNode->letter);
        currNode = currNode->next;
    }

    printf("\n");
}

void insert (char letter){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL){
        node->next = tail;
        node->letter = letter;
        head = node;
    } else {
        struct Node *prevNode = head;
        struct Node *currNode = head;

        while (currNode != NULL){
            if (currNode->letter > letter){
                prevNode = currNode;
                currNode = currNode->next;
            } else {
                break;
            }
        }

        prevNode->next = node;
        node->next = currNode;
        node->letter = letter;

    }
}
