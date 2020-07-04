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
    insert('a');
    insert('b');
    insert('a');
    insert('z');

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
    node->letter = letter;
    if (head == NULL){
        node->next = tail;
        head = node;
    } else {
        struct Node *prevNode = head;
        struct Node *currNode = head;

        while (currNode != NULL){
             if (currNode->letter > letter) {
                break;
            }
            prevNode = currNode;
            currNode = currNode->next;
        }

        if (head == currNode){
            node->next = head;
            head = node;
        } else {
            prevNode->next = node;
            node->next = currNode;
        }


    }
}
