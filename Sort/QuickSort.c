#include <stdio.h>
#include <malloc.h>

// function prototypes
void printArray(int *, int);
int quickSort(int *, int, int);
void sort(int *, int);
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
    printArray(a, size);

    sort(a, size);

    return 0;
}

void sort(int *array, int arrLength) {

    int splitIndex = quickSort(array, 0, arrLength-1);
    printf("Array after first pivot \n");
    printArray(array, arrLength);

    // quicksort the left side (values < pivot value)
    quickSort(array, 0, splitIndex-1);
    printf("Array after left half sort \n");
    printArray(array, arrLength);

    // quicksort the right side (values > pivot value)
    quickSort(array, splitIndex+1, arrLength-1);
    printf("Array after right half sort \n");
    printArray(array, arrLength);
}

int quickSort(int *array, int left, int right) {

    int temp, pivot = left;
    left += 1;

    while( left <= right ) {
        if(array[left] > array[pivot]) {
            if(array[right] < array[pivot]) {
                printf(" swapping %d and %d indexes\n", left, right);
                swap(array + left, array + right);
                left++;
                right--;
                if(left == right) {
                    break;
                }
            }
            else {
                right--;
            }
        }
        else
            left++;
        if(left >= right) {
            swap(array+pivot, array+right);
            break;
        }
    }
    /*if(right > pivot)
    {
        printf(" swapping %d and %d indexes\n", pivot, right);
        swap(array + pivot, array + right);
        return right;
    }*/
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
    for(i=0; i<arrLength; i++) {
        printf("%d\t", *(array + i));
    }
    printf("\n");
}
