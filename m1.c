#include<stdio.h>
#define MAX 20


int lb, mid, ub;
int merge(int a[], int lb, int mid, int ub){
    int i, j, k;
    i=lb;
    j=mid+1;
    k=lb;
    int b[ub];
    while(i <= mid && j <= ub){
        if(a[i] <= a[j]){
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while(i <= mid){
        b[k] = a[i];
        i++;
        k++;
    }

    while(j <= ub){
        b[k] = a[j];
        j++;
        k++;
    }
    for(i = lb; i <= ub; i++){
        a[i] = b[i];
    }
}
int sort(int a[],int lb,int ub){
    if(lb < ub){
        mid = (lb + ub) / 2;
        sort(a, lb, mid);
        sort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}


int main(){
    int a[MAX],i,n;
    printf("Enter the number of elements (max 20): ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    if(n > MAX || n <= 0){
        printf("Invalid number of elements. Please enter a number between 1 and %d.\n", MAX);
        return 1;
    }
    for(i=0; i<n; i++){
        printf("Element %d: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("You entered:\n");
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    sort(a, 0, n-1);
    printf("\nSorted array:\n");
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}