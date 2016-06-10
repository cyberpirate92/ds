/*
 * Simple Stack
 * @author: cyberpirate92
 */

#include<stdio.h>
#include<malloc.h>

// global variable, must be accessible to all functions
// top is used to point to the next empty index in the stack
int top = 0, size;

// function prototypes
int getInput(char *);
int push(int *, int);
int pop(int *);
void display(int *);

int main() {
    int *stack;
    int choice, data;

    size = getInput("Size of stack : ");

    // setting size of stack
    stack = (int *) malloc (sizeof(int) * size);

    do {
        printf(" *** MENU *** \n");
        printf("1. PUSH \n");
        printf("2. POP \n");
        printf("3. EMPTY STACK \n");
        printf("4. EXIT \n");
        printf("Current Stack | ");
        display(stack);
        choice = getInput("CHOICE: ");

        if(choice == 1) {
            data = getInput("Enter data: ");
            if(push(stack, data) == -1) {
                printf("Stack full. \n");
            }
        }
        else if(choice == 2) {
            data = pop(stack);
            if(data == -1) {
                printf("Stack is empty \n");
            }
            else {
                printf("Popped data : %d \n",data);
            }
        }
        else if(choice == 3) {
            int i;
            for(i=0;i<top;i++) {
                pop(stack);
            }
        }
        else if(choice != 4) {
            printf("Invalid choice");
        }
    } while(choice != 4);
    return 0;
}

/*
 *utility function to get a integer input
 */
int getInput(char *display) {
  int temp;
  printf("%s", display);
  scanf("%d", &temp);
  return temp;
}

/*
 * Add an element to the stack
 */
int push(int *pointer, int value) {
    if(top < size) {
        *(pointer + top) = value;
        top++;
        return 1;
    }
    return -1;
}

/*
 * Remove the last element from the stack
 */
int pop(int *pointer) {
    if(top > 0) {
        top--;
        return *(pointer + top);
    }
    return -1;
}

/*
 * Display all the elements of the stack
 */
void display(int *pointer)
{
    int i;
    if(top == 0) {
        printf("Stack empty. \n");
        return;
    }
    for(i = top; i > 0 ; i--) {
        printf("\t%d", *(pointer + i));
    }
    printf("\n");
}
