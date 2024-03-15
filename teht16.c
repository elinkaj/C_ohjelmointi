#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int number;
    struct node *next;
} nnode;

nnode *head = NULL;

void insertNumber(int num) {
    nnode *newNode = (nnode *)malloc(sizeof(nnode));
    if (newNode == NULL) {
        printf("Allocation of memory failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->number = num;
    newNode->next = head;
    head = newNode;
}

void printNumbers() {
    nnode *current = head;
    while (current != NULL) {
        printf("%d ", current->number);
        current = current->next;
    }
    printf("\n");
}

void freeMemory() {
    nnode *current = head;
    while (current != NULL) {
        nnode *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    char input[10];
    int num;
    while (1) {
        printf("Enter a number or 'end' to stop: ");
        scanf("%s", input);
        if (strcmp(input, "end") == 0) {
            printf("Numbers entered: ");
            printNumbers();
            freeMemory();
            break;
        } else if (sscanf(input, "%d", &num) == 1) {
            insertNumber(num);
        } else {
            printf("Invalid input. Please enter a number or 'end'.\n");
            fflush(stdin);
        }
    }
    return 0;
}

