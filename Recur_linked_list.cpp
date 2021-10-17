#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};
Node* head;
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    /* HERE HEAD IS POINTED AS THE NEW NODE ADDRESS AND THE PREVIOUS HEAD ADDRESSES IS PASSED ON TO THE NEXT */
}

void Print_recur(Node* n) // Printing the list in normal order using Recurrsion
{
    if(n == NULL)
    {
        return;
    }
    cout<<n->data<<endl;
    Print_recur(n->next);
}

void RevRecur(Node* n) // Printing the list in reverse order using Recurrsion
{
    if(n == NULL)
    {
        return;
    }
    RevRecur(n->next);
    cout<<n->data<<endl;
}

void RecurReverse(Node* n) // Reversing the whole linked list using Recurrsion
{
    if(n->next == NULL)
    {
        head = n;
        return;

    }
    RecurReverse(n->next);
    Node* p = n->next;
    p->next = n;
    n->next = NULL;
}


void Printlist(Node* node)
{
    while(node != NULL)
    {
        cout<<node->data<<endl;
        node = node->next;
    }
}

int main()
{
    head = NULL;
    //append(&head, 10);
    push(&head, 9);
    push(&head, 11);
    //insert(head->next, 22);
    //append(&head, 24);
    push(&head,22);
    push(&head,44);
    push(&head,99);
    cout<<"Normal forward print using recur"<<endl;
    Print_recur(head);
    cout<<"Reverse Print using recur"<<endl;
    RevRecur(head);
    cout<<"Reversing Link List using Recur"<<endl;
    RecurReverse(head);
    Printlist(head);
}