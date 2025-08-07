#include <stdio.h>

int main() {
    int a[50], n, elem, flag, i, ch, p;
    do {
        flag = 0;
        printf("\nEnter the size of the array: ");
        scanf("%d", &n);
        printf("\nEnter the elements: ");
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        printf("\nEnter the element to be searched: ");
        scanf("%d", &elem);
        for (i = 0; i < n; i++) {
            if (a[i] == elem) {
                flag = 1;
                p = i;
                break;
            }
        }
        if (flag == 0) {
            printf("\nItem not found");
        } else {
            printf("\nItem found at position %d", p + 1);
        }
        printf("\nDo you want to continue? Press 1 for Yes, any other key to exit: ");
        scanf("%d", &ch);
    } while (ch == 1);
    return 0;
}
