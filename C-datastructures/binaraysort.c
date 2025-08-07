#include <stdio.h>

int a[50], n;

void sort() {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i, item, low, high, mid, p, flag, ch;
    do {
        flag = 0;
        printf("\nEnter the size of the array: ");
        scanf("%d", &n);
        printf("\nEnter the elements: \n");
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort();
        printf("\nSorted array: ");
        for (i = 0; i < n; i++) {
            printf("%d\t", a[i]);
        }
        printf("\nEnter the item to be searched: ");
        scanf("%d", &item);
        low = 0;
        high = n - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (item < a[mid]) {
                high = mid - 1;
            } else if (item > a[mid]) {
                low = mid + 1;
            } else {
                flag = 1;
                p = mid;
                break;
            }
        }
        if (flag == 0) {
            printf("\nItem not found");
        } else {
            printf("\nItem found at position %d", p + 1);
        }
        printf("\nIf you want to continue, press 1: ");
        scanf("%d", &ch);
    } while (ch == 1);
    return 0;
}
