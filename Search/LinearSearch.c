#include <stdio.h>
#include <malloc.h>

// function prototypes
int doLinearSearch(int *, int, int);
void printArray(int *, int);

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

    do {
        int data;
        printf("Number to search: ");
        scanf("%d", &data);
        int index = doLinearSearch(a, size, data);
        if(index == -1) {
            printf("%d not found.\n", data);
        }
        else {
            printf("%d found at position %d. \n", data, index);
        }
    }while(1);
}

int doLinearSearch(int *array, int arrLength, int searchData) {
    int i;
    for(i=0; i<arrLength; i++) {
        if (array[i] == searchData) {
            return i;
        }
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
