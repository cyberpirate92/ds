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
void inOrderTraversal(TreeNode*);
void preOrderTraversal(TreeNode*);
void postOrderTraversal(TreeNode*);

int main() {

    // The root node does not have any parents
    TreeNode *root, *temp;
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
                if(temp == NULL) {
                    temp = root;
                }
                break;
            case 2:
                data = getInput("Element to delete : ");
                deleteFromTree(root, data);
                break;
            case 3:
                printf("\n\nIn-order: ");
                inOrderTraversal(temp);
                printf("\n\nPre-Order: ");
                preOrderTraversal(temp);
                printf("\n\nPost-Order: ");
                postOrderTraversal(temp);
                printf("\n\n");
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

void inOrderTraversal(TreeNode *rootNode) {
    if(rootNode != NULL) {
        inOrderTraversal(rootNode->left);
        printf("\t %d", rootNode->data);
        inOrderTraversal(rootNode->right);
    }
}

void preOrderTraversal(TreeNode *rootNode) {
    if(rootNode != NULL) {
        printf("\t %d", rootNode->data);
        preOrderTraversal(rootNode->left);
        preOrderTraversal(rootNode->right);
    }
}

void postOrderTraversal(TreeNode *rootNode) {
    if(rootNode != NULL) {
        postOrderTraversal(rootNode->left);
        postOrderTraversal(rootNode->right);
        printf("\t %d",rootNode->data);
    }
}
