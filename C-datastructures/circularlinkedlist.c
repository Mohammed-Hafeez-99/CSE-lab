#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *h, *last;

void addbeg() {
    int item;
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &item);
    new->data = item;
    if (h->link == NULL) {
        h->link = new;
        new->link = new;
        last = new;
    } else {
        new->link = h->link;
        h->link = new;
        last->link = new;
    }
}

void addbtw() {
    int item, key;
    struct node *new, *ptr;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &item);
    printf("Enter the key: ");
    scanf("%d", &key);
    new->data = item;
    ptr = h->link;
    while (ptr->data != key && ptr->link != h->link) {
        ptr = ptr->link;
    }
    if (ptr->data != key) {
        printf("Insertion not possible\n");
    } else {
        new->link = ptr->link;
        ptr->link = new;
        if (ptr == last) {
            last = new;
        }
    }
}

void addend() {
    int item;
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &item);
    new->data = item;
    if (h->link == NULL) {
        h->link = new;
        new->link = new;
        last = new;
    } else {
        new->link = last->link;
        last->link = new;
        last = new;
    }
}

void disp() {
    struct node *ptr;
    if (h->link == NULL) {
        printf("List Empty\n");
        return;
    }
    ptr = h->link;
    do {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    } while (ptr != h->link);
    printf("\n");
}

void delbeg() {
    struct node *ptr;
    if (h->link == NULL) {
        printf("List Empty\n");
        return;
    }
    ptr = h->link;
    if (ptr->link == ptr) {
        h->link = NULL;
        free(ptr);
    } else {
        h->link = ptr->link;
        last->link = h->link;
        free(ptr);
    }
}

void delend() {
    struct node *ptr, *tmp;
    if (h->link == NULL) {
        printf("List Empty\n");
        return;
    }
    ptr = h->link;
    if (ptr->link == ptr) {
        h->link = NULL;
        free(ptr);
    } else {
        while (ptr->link != h->link) {
            tmp = ptr;
            ptr = ptr->link;
        }
        tmp->link = h->link;
        last = tmp;
        free(ptr);
    }
}

void delbtw() {
    int key;
    struct node *ptr, *tmp;
    if (h->link == NULL) {
        printf("List Empty\n");
        return;
    }
    printf("Enter the key: ");
    scanf("%d", &key);
    ptr = h->link;
    while (ptr->data != key && ptr->link != h->link) {
        tmp = ptr;
        ptr = ptr->link;
    }
    if (ptr->data != key) {
        printf("Deletion not possible\n");
    } else {
        if (ptr == h->link) {
            delbeg();
        } else if (ptr == last) {
            delend();
        } else {
            tmp->link = ptr->link;
            free(ptr);
        }
    }
}

int main() {
    int ch;
    h = (struct node *)malloc(sizeof(struct node));
    h->link = NULL;
    do {
        printf("\n1:Add beginning\n2:Add between\n3:Add ending\n4:Display\n5:Del beginning\n6:Del ending\n7:Del between\n8:EXIT\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: addbeg(); break;
            case 2: addbtw(); break;
            case 3: addend(); break;
            case 4: disp(); break;
            case 5: delbeg(); break;
            case 6: delend(); break;
            case 7: delbtw(); break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    } while (ch <= 8);
    return 0;
}
