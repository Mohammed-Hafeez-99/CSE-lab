#include <stdio.h>

int a[100], n;

void bubble();

int main() {
    int i;
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    bubble();
    return 0;
}

void bubble() {
    int i, j, k, temp;
    printf("Unsorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        printf("Pass %d: \t", i + 1);
        for (k = 0; k < n; k++) {
            printf("%d ", a[k]);
        }
        printf("\n");
    }

    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
