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
int size ();

struct Node *head = NULL;
struct Node *tail = NULL;

int main() {
    printf("Would you like to insert, print, remove, or exit?\n>");
    char choice[10];
    scanf("%s", choice);

    while (strcmp(choice, "exit") != 0) {
        char letter = NULL;
        if (strcmp(choice, "insert") == 0){
            scanf("%s", &letter);
            insert(letter);
        } else if (strcmp(choice, "print") == 0){
            print();
        } else if (strcmp(choice, "remove") == 0){
            printf("Remove has been chosen; to be implemented.\n");
        } else {
            printf("Error; not a valid choice.\n");
        }
        printf(">");
        scanf("%s", choice);
    }

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
        struct Node *prevNode = NULL;
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

int size (){
    int size = 0;
    struct Node *currNode = head;
    while (currNode != NULL){
        ++size;
        currNode = currNode->next;
    }
    return size;
}
