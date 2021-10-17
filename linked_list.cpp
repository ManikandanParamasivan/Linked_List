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

void insert(Node* prev_node, int new_data)
{
    if(prev_node == NULL)
    {
        cout<<"The previous node can not be NULL"<<endl;
        return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;

    /* HERE WE WILL POINT THE NEW NODE ADDRESS TO THE NEXT ONE AND THE POINT PERVIOUS NODE TO THE NEW ONE */
}

void append(Node** head_ref, int new_data)
{
    Node* new_node  = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    return;
    /* WE WILL TRAVERSE THE WHOLE LIST AND ASSIGN THE NEW NODE ADDRESS TO NULL AND POINT THE LAST NODE ADDRESS TO THE NEW ONE */
    
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
    append(&head, 10);
    push(&head, 9);
    push(&head, 11);
    insert(head->next, 22);
    append(&head, 24);
    Printlist(head);
    return 0;
}