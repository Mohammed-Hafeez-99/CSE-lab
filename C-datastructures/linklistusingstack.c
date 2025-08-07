#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *top;
} *h;

void push() {
    int item;
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &item);
    new_node->data = item;
    new_node->top = h;
    h = new_node;
}

void disp() {
    struct node *ptr = h;
    if (ptr == NULL) {
        printf("List Empty\n");
    } else {
        while (ptr != NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->top;
        }
        printf("\n");
    }
}

void pop() {
    struct node *ptr = h;
    if (ptr == NULL) {
        printf("List Empty\n");
    } else {
        h = ptr->top;
        free(ptr);
    }
}

int main() {
    int ch;
    h = NULL;
    do {
        printf("\n1: Push\n2: Pop\n3: Display\n4: Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: disp(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    } while (ch <= 4);
    return 0;
}
