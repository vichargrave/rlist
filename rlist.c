#include <stdio.h>
#include <stdlib.h>

typedef struct node_t node_t;
struct node_t
{
    int     m_value;
    node_t* m_next;
};

node_t* createNode(int value)
{
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if ( newNode )
    {
        newNode->m_value = value;
        newNode->m_next = NULL;
    }
    return newNode;
}

void addNode(node_t** list, int value)
{
    if ( !*list )
    {
        *list = createNode(value);
        return;
    }
    node_t* listPtr = *list;
    while (listPtr->m_next)
    {
        listPtr = listPtr->m_next;
    }
    listPtr->m_next = createNode(value);
}

void printList(node_t* list)
{
    while (list)
    {
        printf("%d  ", list->m_value);
        list = list->m_next;
    }
    printf("\n");
}

node_t* reverseList(node_t* head)
{
    node_t* cursor = NULL;
    node_t* next;
    while (head)
    {
        next = head->m_next;
        head->m_next = cursor;
        cursor = head;
        head = next;
    }
    return cursor;
}

int main(int argc, char** argv)
{
    int i;
    node_t* head = NULL;

    for (i = 0; i < 20; i++) {
        addNode(&head, i);
    }
    printList(head);
    head = reverseList(head);
    printList(head);
    
    exit(0);
}
