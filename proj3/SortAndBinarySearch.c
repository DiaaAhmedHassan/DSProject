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
int main(){

    int arr[6];
    arr[0]=2;
    arr[1]=5;
    arr[2]=7;
    arr[3]=6;
    arr[4]=3;
    arr[5]=1;
    int n=sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n);
}