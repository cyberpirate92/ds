#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int length) {
    printf("\n # High : %d \n", length);
    for(int i=0; i<length; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void merge(int *arr, int low, int high) {
    int mid = (low + high) / 2;
    for(int i=low; i<=mid; i++) {
        for(int j=mid+1; j<=high; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                //break; // {EXPERIMENTAL!!}
            }
        }
    }
    printArray(arr, high);
}

void mergeSort(int *arr, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2; // for splitting the array
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, high-1);
    }
}

int main() {
    int *arr, size;
    printf("\n How many elements ? ");
    scanf("%d", &size);
    arr = (int*)malloc(sizeof(int) * size);
    for(int i=0;i<size;i++) {
        printf("%d => ",(i+1));
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, size);
    printf("Final sorted array");
    printArray(arr,size);
    return 0;
}
