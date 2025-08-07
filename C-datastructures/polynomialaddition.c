#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff, exp;
    struct node *link;
} *Pheader, *Qheader, *Rheader;

void readpoly(struct node *ptr, int n) {
    int i;
    struct node *new;
    for (i = 0; i < n; i++) {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient: ");
        scanf("%d", &new->coeff);
        printf("Enter the exponent: ");
        scanf("%d", &new->exp);
        new->link = NULL;
        if (ptr->link == NULL) {
            ptr->link = new;
        } else {
            struct node *temp = ptr->link;
            while (temp->link != NULL) {
                temp = temp->link;
            }
            temp->link = new;
        }
    }
}

void disp(struct node *ptr1) {
    struct node *ptr = ptr1->link;
    while (ptr != NULL) {
        printf("%dx^%d", ptr->coeff, ptr->exp);
        if (ptr->link != NULL) {
            printf(" + ");
        }
        ptr = ptr->link;
    }
    printf("\n");
}

void addpoly(struct node *p, struct node *q) {
    struct node *Pptr = p->link, *Qptr = q->link, *Rptr = Rheader;
    while (Pptr != NULL && Qptr != NULL) {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        if (Pptr->exp == Qptr->exp) {
            new->coeff = Pptr->coeff + Qptr->coeff;
            new->exp = Pptr->exp;
            Pptr = Pptr->link;
            Qptr = Qptr->link;
        } else if (Pptr->exp > Qptr->exp) {
            new->coeff = Pptr->coeff;
            new->exp = Pptr->exp;
            Pptr = Pptr->link;
        } else {
            new->coeff = Qptr->coeff;
            new->exp = Qptr->exp;
            Qptr = Qptr->link;
        }
        new->link = NULL;
        if (Rptr->link == NULL) {
            Rptr->link = new;
        } else {
            Rptr = Rptr->link;
            Rptr->link = new;
        }
    }
    while (Pptr != NULL) {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->coeff = Pptr->coeff;
        new->exp = Pptr->exp;
        new->link = NULL;
        Rptr->link = new;
        Rptr = Rptr->link;
        Pptr = Pptr->link;
    }
    while (Qptr != NULL) {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->coeff = Qptr->coeff;
        new->exp = Qptr->exp;
        new->link = NULL;
        Rptr->link = new;
        Rptr = Rptr->link;
        Qptr = Qptr->link;
    }
}

int main() {
    int n, m;
    Pheader = (struct node *)malloc(sizeof(struct node));
    Qheader = (struct node *)malloc(sizeof(struct node));
    Rheader = (struct node *)malloc(sizeof(struct node));
    Pheader->link = Qheader->link = Rheader->link = NULL;
    printf("Enter the number of elements of the first polynomial: ");
    scanf("%d", &n);
    readpoly(Pheader, n);
    printf("Enter the number of elements of the second polynomial: ");
    scanf("%d", &m);
    readpoly(Qheader, m);
    printf("First polynomial: ");
    disp(Pheader);
    printf("Second polynomial: ");
    disp(Qheader);
    addpoly(Pheader, Qheader);
    printf("Sum of polynomials: ");
    disp(Rheader);
    return 0;
}
