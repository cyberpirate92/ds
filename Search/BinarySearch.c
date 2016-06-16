#include <stdio.h>
#include <malloc.h>

// function prototypes
int doBinarySearch(int *, int, int);
void printArray(int *, int);
void sort(int *, int);

int main() {

    int *a, i, size;

    printf("Enter size of array: ");
    scanf("%d", &size);
    a = (int *) malloc(sizeof(int) * size);

    for(i=0; i<size; i++) {
        printf("Element %d: ", (i+1));
        scanf("%d", (a + i));
    }

    // sort the array
    sort(a, size);
    printf("Array after sort \n");
    printArray(a, size);

    do {
        int data;
        printf("Number to search: ");
        scanf("%d", &data);
        int index = doBinarySearch(a, size, data);
        if(index == -1) {
            printf("%d not found.\n", data);
        }
        else {
            printf("%d found at position %d. \n", data, index);
        }
    }while(1);
}

int doBinarySearch(int *array, int arrLength, int searchData) {
    int left, right, mid;
    left = 0;
    right = arrLength - 1;
    mid = (left + right) / 2;

    // since array is sorted,
    if(searchData > array[right] || searchData < array[left] ) {
        return -1;
    }

    while(left >= 0 && left <= right && right <= arrLength) {
        if(searchData == array[mid]) {
            return mid;
        }
        else if(searchData == array[left]) {
            return left;
        }
        else if(searchData == array[right]) {
            return right;
        }
        else if(searchData > array[mid]) {
            left = mid;
        }
        else {
            right = mid;
        }
        mid = (left + right) / 2;
    }
    return -1;
}

void printArray(int *array, int arrLength) {
    int i;
    for(i=0; i<arrLength; i++) {
        printf("%d\t", *(array + i));
    }
    printf("\n");
}

void sort(int *array, int arrLength) {
    int i, j;
    for(i=0; i<arrLength; i++) {
        for(j=i+1; j<arrLength; j++) {
            if(array[j] < array[i]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
