#include<stdlib.h>
#include<stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct BSTNode {
    int data;
    struct BSTNode *left, *right;
} TreeNode;

int getInput(char *message) {
    int data;
    printf("%s", message);
    scanf("%d", &data);
    return data;
}

TreeNode* getNewNode(int value) {
    TreeNode *newNode = (TreeNode *) malloc (sizeof(TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addNodeToTree(TreeNode *rootNode, TreeNode *nodeToAdd) {
    if(nodeToAdd->data < rootNode->data) {
        if(rootNode->left == NULL) {
            rootNode->left = nodeToAdd;
        }
        else {
            addNodeToTree(rootNode->left, nodeToAdd);
        }
    }
    else {
        if(rootNode->right == NULL) {
            rootNode->right = nodeToAdd;
        }
        else {
            addNodeToTree(rootNode->right, nodeToAdd);
        }
    }
}

int nodeExists(TreeNode *root, int value) {
    if(root != NULL) {
        if(root->data == value) {
            return TRUE;
        }
        else if(value < root->data) {
            return nodeExists(root->left, value);
        }
        else {
            return nodeExists(root->right, value);
        }
    }
    return FALSE;
}

void inOrder(TreeNode *node) {
    if(node == NULL) {
        return;
    }
    inOrder(node->left);
    printf("%d\t", node->data);
    inOrder(node->right);
}

void preOrder(TreeNode *node) {
    if(node == NULL) {
        return;
    }
    printf("%d\t", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(TreeNode *node) {
    if(node == NULL) {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    printf("%d\t", node->data);
}

void traversals(TreeNode *rootNode) {
    printf("\n\nIn order   : ");
    inOrder(rootNode);
    printf("\n\nPre order  : ");
    preOrder(rootNode);
    printf("\n\nPost Order :");
    postOrder(rootNode);
    printf("\n\n");
}

int main() {
    int choice, data;
    TreeNode *rootNode = NULL, *backup = NULL;
    do {
        printf(". . . . . MENU . . . . . \n");
        printf("1. Add Node \n");
        printf("2. Search Node \n");
        printf("3. Traversals \n");
        printf("4. Exit \n");
        choice = getInput("Your choice: ");
        switch(choice) {
            case 1:
                data = getInput("Data to add: ");
                if(rootNode != NULL) {
                    addNodeToTree(rootNode, getNewNode(data));
                }
                else {
                    rootNode = getNewNode(data);
                }
                break;
            case 2:
                data = getInput("Data to search: ");
                if(nodeExists(rootNode, data)) {
                    printf("Node with data %d exists. \n", data);
                }
                else {
                    printf("Node with data %d does not exist. \n", data);
                }
                break;
            case 3:
                traversals(rootNode);
                break;
            case 4:
                printf("Bye! \n");
                break;
            default:
                printf("Invalid choice! \n");
        }
    } while(choice != 4);
    return 0;
}
