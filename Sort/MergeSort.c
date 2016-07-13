#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int length) {
    for(int i=0; i<length; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int* splitArray(int array[], int from, int to) {
    int *split = (int *) malloc(sizeof(int) * (to-from));
    for(int i=from, j=0; i<to; i++, j++)
        split[j] = array[i];
    return split;
}

void mergeSort(int *array, int arrLen) {
    if(arrLen > 1) {
        int mid = arrLen/2;
        int *leftHalf, *rightHalf;
        int leftHalfLength, rightHalfLength;

        leftHalf = splitArray(array, 0, mid);
        leftHalfLength = mid;

        rightHalf = splitArray(array, mid, arrLen);
        rightHalfLength = arrLen-mid;

        mergeSort(leftHalf, leftHalfLength);
        mergeSort(rightHalf, rightHalfLength);

        int i,j,k;
        i = 0;
        j = 0;
        k = 0;

        while( i<leftHalfLength && j<rightHalfLength) {
            if(leftHalf[i] < rightHalf[j])
                array[k++] = leftHalf[i++];
            else
                array[k++] = rightHalf[j++];
        }
        while(i < leftHalfLength) {
            array[k++] = leftHalf[i++];
        }
        while(j < rightHalfLength) {
            array[k++] = rightHalf[j++];
        }
        free(leftHalf);
        free(rightHalf);
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
    mergeSort(arr, size);
    printf("Final sorted array: \t");
    printArray(arr,size);
    return 0;
}
