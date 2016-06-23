#include<stdio.h>
#include<malloc.h>

// structure for linked list
typedef struct element {
    int data;
    struct element *next;
}node;

// function prototypes
int getInput(char*);
int getCount(node *);
node* push(node *, int);
node* pop(node *);
void view(node *);

int main() {

    int data, choice;
    node *head;

    do {
        printf("\n Number of elements in stack: %d \n", getCount(head));
        printf(" 1. Push \n");
        printf(" 2. Pop \n");
        printf(" 3. View \n");
        printf(" 4. Exit \n\n");
        choice = getInput("\t Your choice: ");

        if(choice == 1) {
            data = getInput("\t Enter data: ");
            head = push(head, data);
        }
        else if(choice == 2) {
            head = pop(head);
        }
        else if(choice == 3) {
            view(head);
        }
        else if(choice != 4) {
            printf(" Invalid choice!");
        }

    } while(choice!=4);
    return 0;
}

// utility function for input
int getInput(char *msg) {
    int input;
    printf("%s",msg);
    scanf("%d", &input);
    return input;
}

// push data to the stack
node* push(node *root, int data) {
  if(root == NULL) {
    root = (node *) malloc (sizeof(struct element));
    root->data = data;
    root->next = NULL;
  }
  else {
    node *temp = (node *) malloc (sizeof(struct element));
    temp->data = data;
    temp->next = root;
    root = temp;
  }
  return root;
}

// pop data from stack
node* pop(node *root) {
    if(root == NULL) {
        printf("Stack empty \n");
        return root;
    }
    else {
        node *temp = root;
        printf("%d popped from stack \n", temp->data);
        root = root->next;
        free(temp);
        return root;
    }
}

// view data in stack
void view(node *root) {
    if(root != NULL) {
        while(root != NULL) {
            printf("\t%d", root->data);
            root = root->next;
        }
    }
    else {
        printf("Stack empty. \n");
    }
}

int getCount(node *root) {
    if(root == NULL) {
        return 0;
    }
    else {
        int count = 0;
        while(root != NULL) {
            count++;
            root = root->next;
        }
        return count;
    }
}
