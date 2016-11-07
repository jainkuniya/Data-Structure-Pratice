#include<stdio.h>

struct node {
    int data;
    struct node * nextNode;
};


typedef struct node Node;

void main(){

    Node* head = (Node*)malloc(sizeof(Node));
    head = NULL;

    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    printList(head);
    insertAfter(&head,5,15);
    printList(head);
    deleteNode(&head,0,3);
    printList(head);

    createStack();

    createQue();
    return;
}

void createQue()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head = NULL;
    enque(&head,85);
    enque(&head,855);
    enque(&head,855);
    enque(&head,895);
    enque(&head,805);
    printList(head);
    deque(&head);
    deque(&head);
    printList(head);
    deque(&head);
    enque(&head,89);
    printList(head);
    deque(&head);
    printList(head);
    deque(&head);
    enque(&head,87);
    printList(head);
    deque(&head);
    printList(head);
}

void enque(Node** head, int data)
{
    insert(head,data);
}

void deque(Node** head)
{
    if(!isEmpty(head))
    {
        deleteNode(head,0,0);
    }else
    {
        printf("Que is empty\n");
    }
}

int isEmpty(Node** head)
{
    return *head == NULL;
}

void createStack()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head = NULL;
    int count =-1;
    int* pCount = &count;
    push(&head,4,pCount);
    push(&head,54,pCount);
    push(&head,94,pCount);
    push(&head,43,pCount);
    printList(head);
    pop(&head, pCount);
    printList(head);
    peek(head);
    push(&head,483,pCount);
    printList(head);
    pop(&head, pCount);
    printList(head);
    peek(head);
    printList(head);
}

void peek(Node* head)
{
    while(head->nextNode != NULL)
    {
        head = head->nextNode;
    }
    printf("Top value of stack is %d\n",head->data);
}

void pop(Node** head,int* pCount)
{

   // printf("%d\n",*pCount);
   deleteNode(head,0,*pCount);
    (*pCount)--;
}

void push(Node** head, int data, int* pCount)
{
    insert(head,data);
   // printf("%d\n",((*pCount)++));
    (*pCount) = *pCount + 1;
}
void deleteNode(Node** head,int type ,int poData )
{
    if(*head!=NULL)
    {
        Node* temp = *head;
        if(type==0)
        {
            int count =0;
            Node* previous = NULL;
            while(temp != NULL && count< poData)
            {
                count++;
                previous = temp;
                temp = temp->nextNode;
            }
            if(count == poData)
            {
                if(previous != NULL)
                {
                    if(temp != NULL)
                    {
                        previous->nextNode = temp->nextNode;
                    }
                }else
                {
                    *head = (*head)->nextNode;
                }
            }
        }else if(type == 1)
        {
            Node* previous = NULL;
            while(temp != NULL )
            {

                if(poData == temp->data)
                {

                    break;
                }
                previous = temp;
                temp = temp->nextNode;
            }
            if(previous!=NULL )
            {
                if(temp != NULL && temp->data == poData)
                {
                    previous->nextNode = temp->nextNode;
                }
            }else
            {
                *head = (*head)->nextNode;
            }
        }
    }
}

void insert(Node** head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp->nextNode != NULL)
    {
        temp = temp->nextNode;
    }
    temp->nextNode = newNode;
    return;
}

void insertAfter(Node **head, int after, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data =data;
    if(*head == NULL)
    {
        newNode->nextNode = NULL;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp != NULL)
    {
        if(temp->data == after)
        {
            newNode->nextNode = temp->nextNode;
            temp->nextNode = newNode;
            break;
        }
        temp = temp->nextNode;
    }
}

void printList(Node* head){
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->nextNode;
    }
    printf("\n");
}
