#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    /* HERE HEAD IS POINTED AS THE NEW NODE ADDRESS AND THE PREVIOUS HEAD ADDRESSES IS PASSED ON TO THE NEXT */
}

void Reverse_List(Node**head_ref)
{
    Node* curr = (*head_ref);
    Node* next = NULL;
    Node* prev = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*head_ref) = prev;
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
    Node* head = NULL;
    //append(&head, 10);
    push(&head, 9);
    push(&head, 11);
    //insert(head->next, 22);
    //append(&head, 24);
    push(&head,22);
    push(&head,44);
    cout<<"Before Reverse :- "<<endl;
    Printlist(head);
    cout<<"After Reverse :- "<<endl;

    Reverse_List(&head);
    Printlist(head);
}