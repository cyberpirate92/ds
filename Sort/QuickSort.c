#include <stdio.h>
#include <malloc.h>
#define TRUE 1
#define FALSE 0

// function prototypes
void printArray(int *, int);
int quickSort(int *, int, int);
void sort(int *, int, int);
void swap(int *, int *);

int main() {
    int *a, i, size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    a = (int *) malloc(sizeof(int) * size);
    for(i=0; i<size; i++) {
        printf("Element %d: ", (i+1));
        scanf("%d", (a + i));
    }
    printf("Initial array \n");
    printArray(a, size-1);
    sort(a, 0, size-1);
    return 0;
}

void sort(int *array, int left, int right) {
    if(left < right) {
        int splitIndex = quickSort(array, left, right);
        printf("Array after first pivot \n");
        printArray(array, right);

        // quicksort the left side (values < pivot value)
        sort(array, left, splitIndex-1);

        // quicksort the right side (values > pivot value)
        sort(array, splitIndex+1, right);
    }
}

int quickSort(int *array, int pivot, int right) {
    int left = pivot +1;
    int done = FALSE;
    while( !done ) {
        while( left < right && array[left] < array[pivot] ) {
            left++;
        }
        while( right >= left && array[right] > array[pivot] ) {
            right--;
        }
        if(right <= left)
            done = TRUE;
        else
            swap(array +left, array + right);
    }
    swap(array + right, array + pivot);
    return right;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *array, int arrLength) {
    int i;
    for(i=0; i<=arrLength; i++) {
        printf("%d\t", *(array + i));
    }
    printf("\n");
}
