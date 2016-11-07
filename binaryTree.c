#include<stdio.h>
struct node {
    int data;
    struct node * leftNode;
    struct node * rightNode;
};

typedef struct node Node;

struct stackNode{
    Node* node;
    struct stackNode* nextNode;
};

typedef struct stackNode StackNode;

void pushStack(StackNode** stackHead, Node* node)
{
    StackNode* stuckNode = (StackNode*)malloc(sizeof(StackNode));
    stuckNode->node = node;
    stuckNode->nextNode = NULL;
    if(*stackHead == NULL)
    {
        *stackHead = stuckNode;
        return;
    }
    StackNode* temp = *stackHead;
    while(temp->nextNode!=NULL)
    {
        temp = temp->nextNode;
    }
    temp->nextNode = stuckNode;
}

void popStack(StackNode** head)
{
    if(*head==NULL)
        return;
    StackNode* temp = *head;
    StackNode* previous = NULL;
    while(temp->nextNode!=NULL)
    {
        previous = temp;
        temp = temp->nextNode;
    }
    if(previous == NULL)
    {
        *head=NULL;
    }else
    {
        previous->nextNode= NULL;
    }
}

StackNode* peekStack(StackNode** head)
{
    if(*head==NULL)
        return;
    StackNode* temp = *head;
    while(temp->nextNode!=NULL)
    {
        temp = temp->nextNode;
    }
    return temp;
}

void printList(StackNode* head)
{
    while(head!=NULL)
    {
        Node* node = head->node;
        printf("%d ",node->data);
        head = head->nextNode;
    }
    printf("\n");
}

void printInorderIteration(Node* head)
{
    StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));
    stackNode = NULL;
    int cont = 1;
    while(cont == 1)
    {
        if(head!=NULL)
        {
            pushStack(&stackNode,head);
            head = head->leftNode;
        }else
        {
            if(stackNode!=NULL)
            {
                head= peekStack(&stackNode)->node;
                popStack(&stackNode);
                printf("%d ",head->data);
                head = head->rightNode;
            }else{
                cont =0;
            }
        }
    }
    return;
}



void printPostOrderIteration(Node* head)
{
    StackNode* stackHead = (StackNode*)malloc(sizeof(StackNode));
    stackHead =NULL;
    pushStack(&stackHead,head);
    StackNode* stackHead2 = (StackNode*)malloc(sizeof(StackNode));
    stackHead2 =NULL;
    while(stackHead!=NULL)
    {
        head= peekStack(&stackHead)->node;
        popStack(&stackHead);

        pushStack(&stackHead2,head);
     //   printList(stackHead2);
        if(head->leftNode!=NULL)
        {
            pushStack(&stackHead,head->leftNode);
        }
        if(head->rightNode!=NULL)
        {
            pushStack(&stackHead,head->rightNode);
        }
    }

    while(stackHead2!=NULL)
    {
        StackNode* stackNode = peekStack(&stackHead2);
        popStack(&stackHead2);
        printf("%d ",stackNode->node->data);
    }
    return;
}

void printPreOrderIteration(Node* head)
{

    return;
}

void main()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head = NULL;
    insert(&head,5);
    insert(&head,1);
    insert(&head,6);
    insert(&head,9);
    insert(&head,3);
    printf("Inorder traversal :- ");
    printInorder(head);
    printf("\n");
    printf("PostOrder traversal :- ");
    printPostOrder(head);
    printf("\n");
    printf("PreOrder traversal :- ");
    printPreOrder(head);
    printf("\n");

    printf("Inorder traversal Iteration :- ");
    printInorderIteration(head);
    printf("\n");
    printf("PostOrder traversal Iteration:- ");
    printPostOrderIteration(head);
    printf("\n");
    printf("PreOrder traversal Iteration:- ");
    printPreOrderIteration(head);
    printf("\n");

    return;
}



void printPreOrder(Node* head)
{
    if(head==NULL)
    {
        return;
    }
    printf("%d ",head->data);
    if(head->leftNode !=NULL)
    {
        printPreOrder(head->leftNode);
    }
    if(head->rightNode!=NULL)
    {
        printPreOrder(head->rightNode);
    }
}


void printPostOrder(Node* head)
{
    if(head!=NULL)
    {
        printPostOrder(head->leftNode);
        printPostOrder(head->rightNode);
        printf("%d ",head->data);
    }
}

void printInorder(Node* head)
{
    if(head!=NULL)
    {
        if(head->leftNode != NULL)
        {
            printInorder(head->leftNode);
        }
        printf("%d ",head->data);
        if(head->rightNode != NULL)
        {
            printInorder(head->rightNode);
        }
    }
}





void insert(Node** head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->leftNode =NULL;
    newNode->rightNode = NULL;
    newNode->data = data;
    if(*head== NULL)
    {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(1)
    {
        if(data < temp->data)
        {
            if(temp->leftNode != NULL)
            {
                temp = temp->leftNode;
            }else
            {
                temp->leftNode = newNode;
                break;
            }
        }else
        {
            if(temp->rightNode != NULL)
            {
                temp = temp->rightNode;
            }else
            {
                temp->rightNode = newNode;
                break;
            }
        }
    }

}
