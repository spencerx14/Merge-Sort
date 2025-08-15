#include<stdio.h>
#define MAX 20

void merge(int a[], int lb, int mid, int ub) {
    int i = lb, j = mid + 1, k = 0;
    int b[ub - lb + 1]; // temp array

    while(i <= mid && j <= ub) {
        if(a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while(i <= mid) b[k++] = a[i++];
    while(j <= ub) b[k++] = a[j++];

    for(i = lb, k = 0; i <= ub; i++, k++)
        a[i] = b[k];
}

void sort(int a[], int lb, int ub) {
    if(lb < ub) {
        int mid = (lb + ub) / 2;
        sort(a, lb, mid);
        sort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int main() {
    int a[MAX], i, n;
    printf("Enter the number of elements (max 20): ");
    scanf("%d", &n);

    if(n > MAX || n <= 0) {
        printf("Invalid number of elements. Please enter a number between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &a[i]);
    }

    printf("You entered:\n");
    for(i = 0; i < n; i++) printf("%d ", a[i]);

    sort(a, 0, n-1);

    printf("\nSorted array:\n");
    for(i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}
