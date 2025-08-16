#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *left, *right;
} *root = NULL;

void createBT(struct node *tmp) {
    struct node *ptr, *pptr;
    ptr = root;
    if (root == NULL) {
        root = tmp;
    } else {
        while (ptr != NULL) {
            pptr = ptr;
            if (ptr->info > tmp->info) {
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }
        if (pptr->info > tmp->info) {
            pptr->left = tmp;
        } else {
            pptr->right = tmp;
        }
    }
}

void inorder(struct node *ptr) {
    if (ptr != NULL) {
        inorder(ptr->left);
        printf("%d\t", ptr->info);
        inorder(ptr->right);
    }
}

void preorder(struct node *ptr) {
    if (ptr != NULL) {
        printf("%d\t", ptr->info);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct node *ptr) {
    if (ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d\t", ptr->info);
    }
}

int main() {
    int ch, item;
    struct node *New;
    do {
        printf("\n1: Create\n2: Inorder\n3: Preorder\n4: Postorder\n5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                New = (struct node *)malloc(sizeof(struct node));
                printf("Enter node: ");
                scanf("%d", &item);
                New->left = NULL;
                New->right = NULL;
                New->info = item;
                createBT(New);
                break;
            case 2:
                inorder(root);
                printf("\n");
                break;
            case 3:
                preorder(root);
                printf("\n");
                break;
            case 4:
                postorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    } while (ch <= 5);
    return 0;
}