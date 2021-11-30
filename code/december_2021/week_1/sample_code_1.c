/* 
First line should contain the question link.
Ex. https://leetcode.com/problems/linked-list-cycle/
*/


/*
#includes
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
Globals.
*/
struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;
Node *head = NULL;


/*
Helper API to insert node always at the last position.
*/
void insertAtLast(Node *ptr, int value)
{
    Node *last = NULL; 

    // create new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // if list is empty i.e. head or ptr = NULL
    if(ptr == NULL)
    {
        head = newNode;
        last = newNode;
    }
    else
    {
        last = ptr; 
		
		// traverse the list until last pointer reach to last node of list.
        while(last->next != NULL) 
        {
            last = last->next;
        }

        // create the link between last node to the new node and point
        // the last pointer to the new last node.
        last->next = newNode;
        last = newNode;
    }
}


/*
Helper API to display contents of the linkedlist using iterative approach.
*/
void display(Node *ptr)
{
    if(ptr == NULL)
    {
        printf("LINKED LIST is EMPTY\n");
        return;
    }

    while(ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}


/*
API to implement the logic of finding the loop/cycle in the linked list.

Parameters:
Node *ptr: Pointer of Node type.

Return Type: bool
API returns true (1) on success, otherwise return false (0).
*/
bool linkedlist_cycle(Node *ptr)
{
    Node *slow = ptr;
    Node *fast = ptr;

    while(fast != NULL && fast->next != NULL)
    {
        // move fast pointer by two steps and slow pointer by one step in each iteration.
        fast = fast->next->next;
        slow = slow->next;

        // In case two pointers meet, that means cycle is found
        if(slow == fast)
        {
            return true;
        }
    }

    return false;
}


/* 
Driver Code i.e. main()
*/
int main(void)
{
    // Create list by inserting elements always at the end of the linked list.
    insertAtLast(head, 10);
    insertAtLast(head, 20);
    insertAtLast(head, 30);
    insertAtLast(head, 60);
    insertAtLast(head, 50);

    display(head);

    // create loop for testing
    Node *temp1, *temp2;
    temp1 = head->next->next;
    temp2 = head->next->next->next->next;
    temp2->next = temp1;

    printf("\n\n");

    if(linkedlist_cycle(head) == 1)
        printf("Linked List contains LOOP\n");
    else
        printf("Linked List do NOT conatin LOOP\n");

    return 0;
}
