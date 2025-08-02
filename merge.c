#include<stdio.h>

void sort(int a,int lb,int ub){
    int mid;
    if(lb < ub){
        mid = (lb + ub) / 2;
        sort(a, lb, mid);
        sort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int merge(int a[], int lb, int mid, int ub){
    int i, j, k;
    int n1 = mid - lb + 1;
    int n2 = ub - mid;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = a[lb + i];
    for(j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = lb;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        a[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        a[k] = R[j];
        j++;
        k++;
    }
}
int main(){
    int a[8],i;
    printf("Enter 8 elements:\n");
    for(i=0; i<8; i++){
        printf("Element %d: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("You entered:\n");
    for(i=0; i<8; i++){
        printf("%d ", a[i]);
    }
    sort(a, 0, 7);
    printf("\nSorted array:\n");
    for(i=0; i<8; i++){
        printf("%d ", a[i]);
    }
    return 0;
}