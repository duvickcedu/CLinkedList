#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Christian Duvick

//structure for a node
struct Node {
    char letter;
    struct Node *next;
};

//prototypes
void print ();
void insert (char letter);
int size ();
void removeLL();

//structures to help with linked list
struct Node *head = NULL;
struct Node *tail = NULL;

//controls the interface
//by default the program exits with the word exit as that's the
//condition to leave the while loop as long as list is empty
int main() {
    printf("Would you like to insert, print, remove, or exit?\n>");
    char choice[10];
    scanf("%s", choice);

    while (strcmp(choice, "exit") != 0) {
        char letter;
        if (strcmp(choice, "insert") == 0){
            printf("enter a char:");
            scanf("%s", &letter);
            insert(letter);
        } else if (strcmp(choice, "print") == 0){
            print();
        } else if (strcmp(choice, "remove") == 0){
            removeLL();
            printf("Linked list is now empty\n");
        } else {
            printf("Error: unknown request '%s'\n", choice);
        }
        printf(">");
        scanf("%s", choice);

        if ((strcmp(choice, "exit") == 0) && (size() != 0)){
            while (strcmp(choice, "exit") == 0 ){
                printf("Linked List must be empty first\n");
                printf(">");
                scanf("%s", choice);
            }
        }
    }

    return 0;
}

//prints the nodes in order.
void print (){
    struct Node *currNode = head;
    while (currNode != NULL){
        printf("%c ", currNode->letter);
        currNode = currNode->next;
    }

    printf("\n");
}

//Inserts node in order.
void insert (char letter){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));

    if (head == NULL){
        node->next = tail;
        node->letter = letter;
        head = node;
    } else {
        struct Node *prevNode = NULL;
        struct Node *currNode = head;

        //while stop when currNodes letter is bigger than letter therefore,
        //letter should come before it.
        while (currNode != NULL){
            if (currNode->letter > letter) {
                break;
            }
            prevNode = currNode;
            currNode = currNode->next;
        }

        if (head == currNode){
            node->letter = letter;
            node->next = head;
            head = node;
        } else {
            node->letter = letter;
            prevNode->next = node;
            node->next = currNode;
        }

    }
}

//used for getting size of the Linked List
//useful for checking condition to see that list is empty
int size (){
    int size = 0;
    struct Node *currNode = head;
    while (currNode != NULL){
        ++size;
        currNode = currNode->next;
    }
    return size;
}

//sets head to null then frees space to delete Linked List
void removeLL(){
    head = NULL;
    free(head);
}