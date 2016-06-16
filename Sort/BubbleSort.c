#include <stdio.h>
#include <malloc.h>

// function prototypes
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

    printf("The entered array \n");
    printArray(a, size);

    printf("The sorted Array \n");
    sort(a, size);
    printArray(a, size);

    return 0;
}

void printArray(int *array, int arrLength) {
    int i;
    for(i=0; i<arrLength; i++) {
        printf("%d\t", *(array + i));
    }
    printf("\n");
}

// simple bubble sort
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
