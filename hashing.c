#include<stdio.h>

struct node {
    int data;
    int key;
};

typedef struct node Node;

#define TOTAL_SIZE  10

Node* nodeArray[TOTAL_SIZE];


int getHashIndex(int key)
{
    return key%TOTAL_SIZE;
}

void main()
{
    insert(132,getHashIndex(45),45);
    insert(133,getHashIndex(35),35);
    insert(134,getHashIndex(33),33);
    insert(138,getHashIndex(451),451);
    insert(130,getHashIndex(485),485);
    insert(1378,getHashIndex(2),2);
    insert(13,getHashIndex(4),4);
    printList();
    search(33);
    printList();
    deleteData(33);
    printList();
    insert(1238,getHashIndex(4351),4351);
    insert(1930,getHashIndex(4805),4805);
    printList();
    search(33);
    printList();
    return;
}

void printList()
{
    printf("List is as follows:-\n");
    int i=0;
    for(i=0;i<TOTAL_SIZE;i++)
    {
        if(nodeArray[i] != NULL)
        {
            if(nodeArray[i]->data != -1 && nodeArray[i]->key != -1)
            {
                printf("%d ",nodeArray[i]->data);
            }else
            {
                printf(" ~~ ");
            }
        }else
        {
            printf(" ~~ ");
        }
    }
    printf("\n");
}

void search (int key)
{
    int hashIndex = getHashIndex(key);
    while(1)
    {
        if(nodeArray[hashIndex] != NULL )
        {
            if(nodeArray[hashIndex]->key==key)
            {
                printf("Data with key = %d is %d\n",nodeArray[hashIndex]->data,key);
                break;
            }else
            {
                (hashIndex++)%TOTAL_SIZE;
            }
        }else
        {
            printf("Sorry nothing found with key equal to %d\n",key);
            break;
        }
    }
}

void deleteData(int key)
{
    int hashIndex = getHashIndex(key);
    while(1)
    {
        if(nodeArray[hashIndex] != NULL )
        {
            if(nodeArray[hashIndex]->key==key)
            {
                Node* node = (Node*)malloc(sizeof(Node));
                node->data = -1;
                node->key = -1;
                nodeArray[hashIndex] = node;

                printf("Successfully deleted data with key = %d\n",key);
                break;
            }else
            {
                (hashIndex++)%TOTAL_SIZE;
            }
        }else
        {
            printf("Sorry nothing found with key equal to %d\n",key);
            break;
        }
    }
}

void insert(int data,int hashIndex,int key)
{
    if(nodeArray[hashIndex] == NULL || (nodeArray[hashIndex]->data == -1 && nodeArray[hashIndex]->key == -1) )
    {
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->key = key;
        nodeArray[hashIndex] = node;
        printf("Successfully Inserted %d \n",data);
    }else
    {
        insert(data,(hashIndex+1)%TOTAL_SIZE,key);
    }
    return;
}

