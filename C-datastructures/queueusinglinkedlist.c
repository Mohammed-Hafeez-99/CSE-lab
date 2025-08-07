#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *h;

void enqueue() {
    int item;
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &item);
    new_node->data = item;
    new_node->link = NULL;
    if (h == NULL) {
        h = new_node;
    } else {
        ptr = h;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = new_node;
    }
}

void disp() {
    struct node *ptr = h;
    if (ptr == NULL) {
        printf("List Empty\n");
    } else {
        while (ptr != NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

void dequeue() {
    struct node *ptr;
    if (h == NULL) {
        printf("List Empty\n");
    } else {
        ptr = h;
        h = h->link;
        free(ptr);
    }
}

int main() {
    int ch;
    h = NULL;
    do {
        printf("\n1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: disp(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    } while (1);
    return 0;
}
