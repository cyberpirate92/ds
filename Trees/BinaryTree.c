#include<stdio.h>
#include<stdlib.h>
#define LEFT 0
#define RIGHT 1

typedef struct Node {
    int data;
    struct Node *left, *right;
}TreeNode;

// function prototypes
int getInput(char *);
TreeNode* addToTree(TreeNode*, int);
void deleteFromTree(TreeNode*, int);
void traverseTree(TreeNode*);

int main() {

    // The root node does not have any parents
    TreeNode *root;
    root = NULL;
    int choice, data;

    do {
        printf("... ... Menu ... ... \n");
        printf("1. Add element \n");
        printf("2. Delete element \n");
        printf("3. Traverse Tree \n");
        printf("4. Exit \n");
        choice = getInput("Your Choice: ");
        switch(choice) {
            case 1:
                data = getInput("Element to add : ");
                root = addToTree(root, data);
                break;
            case 2:
                data = getInput("Element to delete : ");
                deleteFromTree(root, data);
                break;
            case 3:
                printf("\n");
                traverseTree(root);
                printf("\n");
                break;
            case 4:
                printf("Bye! \n");
                break;
            default:
                printf("Invalid choice! \n");
        }
    }while(choice != 4);
    return 0;
}

int getInput(char *message) {
    int data;
    printf("%s", message);
    scanf("%d", &data);
    return data;
}

TreeNode* addToTree(TreeNode *rootNode, int data) {
    TreeNode *temp = (TreeNode*) malloc (sizeof(TreeNode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if(rootNode == NULL) {
        rootNode = temp;
    }
    else {
        while(rootNode != NULL) {
            if(data < rootNode->data) {
                if(rootNode->left != NULL) {
                    rootNode = rootNode->left;
                }
                else {
                    rootNode->left = temp;
                    break;
                }
            }
            else {
                if(rootNode->right != NULL) {
                    rootNode = rootNode->right;
                }
                else {
                    rootNode->right = temp;
                    break;
                }
            }
        }
    }
    return rootNode;
}

void deleteFromTree(TreeNode *rootNode, int data) {
    //TODO: node deletion code goes here :)
}

void traverseTree(TreeNode *rootNode) {
    if(rootNode != NULL) {
        traverseTree(rootNode->left);
        printf("\t %d", rootNode->data);
        traverseTree(rootNode->right);
    }
}
