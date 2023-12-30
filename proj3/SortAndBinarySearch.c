#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void bubble_sort(int arr[],int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n-i-1; j++) { // 2
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d", arr[i]);
    }
}

int binarySearch(int arr[], int l, int r, int value)
{
    if (r >= l) {
        int mid = l+((r - l)/2);

        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid] > value)
            return binarySearch(arr, l, mid - 1, value);

        if(arr[mid]< value)
        return binarySearch(arr, mid + 1, r, value);
    }

    return-1;
}

int main(){

    int arr[6];
    arr[0]=2;
    arr[1]=8;
    arr[2]=6;
    arr[3]=4;
    arr[4]=3;
    arr[5]=1;
    int n=sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n);
    printf("\n");
    printf("%s", "found at index: ");
    printf("%d",binarySearch(arr, 0, 5, 8));
}