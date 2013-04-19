/*
   client.cpp

   Test app to reverse a kinked list. 

   ------------------------------------------

   Copyright © 2013 [Vic Hargrave - http://vichargrave.com]

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

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
