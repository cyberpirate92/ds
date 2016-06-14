/*
 * Simple queue implementation [FIFO] using array, with enqueue, dequeue operations
 */

#include<stdio.h>
#define QUEUE_LENGTH 5

// global variables for use by all functions
int queue[QUEUE_LENGTH], start=0, end=0, count=0;

// function prototypes
int getInput(char*);
void enqueue(int);
void dequeue();
void view();
int isQueueFull();
int isQueueEmpty();

int main() {
    int data, choice;
    do {
        printf("\n Number of elements in Queue: %d \n", count);
        printf(" 1. Enqueue \n");
        printf(" 2. Dequeue \n");
        printf(" 3. View \n");
        printf(" 4. Exit \n");
        choice = getInput("\n\n\t Your choice: ");
        if(choice == 1) {
            data = getInput("\n\tEnter data: ");
            enqueue(data);
        }
        else if(choice == 2) {
            dequeue();
        }
        else if(choice == 3) {
            view();
        }
        else if(choice != 4) {
            printf("\t\t Invalid choice! \n");
        }
    } while(choice != 4);
    return 0;
}

// utility function for input
int getInput(char *msg) {
    int input;
    printf("%s",msg);
    scanf(" %d", &input);
    return input;
}

// returns 1 if queue is full, else 0
int isQueueFull() {
    return (start == end ) && (count != 0);
}

// returns 1 if queue is empty, else 0
int isQueueEmpty() {
    return (start == end) && (count == 0);
}

// add data to the queue
void enqueue(int data) {
    if(isQueueFull()) {
        printf("\t\t Queue full. \n");
    }
    else {
        queue[start++] = data;
        start = start % QUEUE_LENGTH;
        count++;
    }
}

// remove data from queue
void dequeue() {
    if(isQueueEmpty()) {
        printf("\t\t Queue is empty. \n");
    }
    else {
        printf("\t\t %d dequeued. \n", queue[end]);
        end = (end + 1) % QUEUE_LENGTH;
        count--;
    }
}

// view elements in the queue
void view() {
    if(isQueueEmpty()) {
        printf("\t\t Queue Empty. \n");
    }
    else {
        int i = end;
        do {
            printf("\t%d", queue[i++]);
            i = i % QUEUE_LENGTH;
        } while(i != start);
        printf("\n");
    }
}
