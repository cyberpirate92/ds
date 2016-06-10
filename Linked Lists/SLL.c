#include<stdio.h>
#include<malloc.h>

typedef struct element
{
  int data;
  struct element *next;
}node;

int getInput(char *);
int countItems(node *);
void traverse(node *);
void addToList(node *, int);
void removeFromList(node *, int);

int main()
{
  // initializing the root node;
  node *root, *temp;
  root = (struct element *) malloc(sizeof(node));
  temp = root;
  temp->next = NULL;

  int choice,data;

  do
  {
    printf("************** \n");
    printf(" # Elements : %d \n",countItems(root));
    printf("**** Menu **** \n");
    printf("1. Add Element \n");
    printf("2. Remove Element \n");
    printf("3. View Elements \n");
    printf("4. Exit \n");
    printf("Your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        data = getInput("Data to add : ");
        addToList(root, data);
        break;
      case 2:
        data = getInput("Data to pop : ");
        removeFromList(root, data);
        break;
      case 3:
        traverse(root->next);
        break;
      case 4:
        printf("Bye! \n");
        break;
      default:
        printf("Invalid choice \n");
    }
  }while(choice != 4);
  return 0;
}

int getInput(char *display)
{
  int temp;
  printf("%s", display);
  scanf("%d", &temp);
  return temp;
}

int countItems(node *head)
{
  int count = 0;
  while(head->next != NULL)
  {
    head = head->next;
    count++;
  }
  return count;
}

void traverse(node *head)
{
  if(head == NULL)
  {
    printf("List empty. \n");
    return;
  }
  while(head != NULL)
  {
    printf("\t%d",head->data);
    head = head->next;
  }
  printf("\n");
}

void addToList(node *head, int data)
{
  while(head->next != NULL)
  {
    head = head->next;
  }
  head->next = (node *) malloc (sizeof(node));
  head = head->next;
  head->data = data;
}

void removeFromList(node *head, int data)
{
  while(head->next != NULL && (head->next)->data != data)
  {
    head = head->next;
  }
  if(head->next == NULL)
  {
    printf("No node found with data %d",data);
    return;
  }
  else
  {
    node *nodeToRemove = head->next;
    head->next = nodeToRemove->next;
    free(nodeToRemove);
    printf("\n Node with data %d has been removed succesfully!",data);
  }
}
