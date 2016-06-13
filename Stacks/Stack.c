#include<stdio.h>
#define STACK_SIZE 5

// global variables for use by all functions
int top = 0, stack[STACK_SIZE];

// function prototypes
int getInput(char*);
void push(int);
void pop();
void view();

int main() {
    int choice, data;

    do {
        printf("\n Number of elements in stack: %d \n", top);
        printf(" 1. Push \n");
        printf(" 2. Pop \n");
        printf(" 3. View \n");
        printf(" 4. Exit \n\n");
        choice = getInput("\t Your choice: ");

        if(choice == 1) {
            data = getInput("\t Enter data: ");
            push(data);
        }
        else if(choice == 2) {
            pop();
        }
        else if(choice == 3) {
            view();
        }
        else if(choice != 4) {
            printf(" Invalid choice!");
        }

    } while(choice!=4);
}

// utility function for input
int getInput(char *msg) {
    int input;
    printf("%s",msg);
    scanf("%d", &input);
    return input;
}

// push data to the stack
void push(int data) {
    if(top < STACK_SIZE) {
        stack[top] = data;
        top++;
    }
    else {
        printf("\n\t\t Stack overflow! \n");
    }
}

// pop data from stack
void pop() {
    if(top <= 0) {
        printf("\n\t\t Stack underflow! \n");
    }
    else {
        printf("\n\t %d popped from stack \n", stack[top--]);
    }
}

// view data in stack
void view() {
    if(top <= 0) {
        printf("\n\t\t Stack is empty. \n");
    }
    else {
        int i;
        printf("\n ** Elements in stack ** \n");
        for(i = top-1; i >= 0; i--) {
            printf("%d\t", stack[i]);
        }
        printf("\n\n");
    }
}
