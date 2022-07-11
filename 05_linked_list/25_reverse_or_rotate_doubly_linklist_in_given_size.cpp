/*
    link: https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
// C++ implementation to reverse a doubly linked list
// in groups of given size
#include <bits/stdc++.h>

using namespace std;

// a node of the doubly linked list
struct Node {
    int data;
    Node* next, * prev;
};

// function to get a new node
Node* getNode(int data)
{
    // allocate space
    Node* new_node = (Node*)malloc(sizeof(Node));

    // put in the data
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

// function to insert a node at the beginging
// of the Doubly Linked List
void push(Node** head_ref, Node* new_node)

// function to reverse a doubly linked list
// in groups of given size
Node* revListInGroupOfGivenSize(Node* head, int k)
{
    Node* current = head;
    Node* temp = NULL;
    Node* newHead = NULL;
    int count = 0;

    // reversing the current group of k
    // or less than k nodes by adding
    // them at the beginning of list
    // 'newHead'
    while (current != NULL && count < k)
    {
        temp= current->next;

    // since we are adding at the beginning,
    // prev is always NULL
    current->prev = NULL;

    // link the old list off the new node
    current->next = (newHead);

    // change prev of head node to new node
    if ((newHead) != NULL)
        (newHead)->prev = current;

    // move the head to point to the new node
    (newHead) = current;


        current = temp;
        count++;
    }

    // if next group exists then making the desired
    // adjustments in the link
    if (temp != NULL)
    {
        head->next = revListInGroupOfGivenSize(temp, k);
        head->next->prev = head;
    }

    // pointer to the new head of the
    // reversed group
    return newHead;
}

// Function to print nodes in a
// given doubly linked list
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver program to test above
int main()
{
    // Start with the empty list
    Node* head = NULL;

    // Create doubly linked: 10<->8<->4<->2
    push(&head, getNode(2));
    push(&head, getNode(4));
    push(&head, getNode(8));
    push(&head, getNode(10));

    int k = 2;

    cout << "Original list: ";
    printList(head);

    // Reverse doubly linked list in groups of
    // size 'k'
    head = revListInGroupOfGivenSize(head, k);

    cout << "\nModified list: ";
    printList(head);

    return 0;
}
