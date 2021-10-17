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

void Delete_element(Node** head_ref, int key)
{
    Node* temp = *head_ref;
    Node* prev = NULL;
    if(temp!= NULL && temp->data == key)
    {
        *head_ref = temp->next;
        delete temp;
        return;
    }
    else{
        while(temp!= NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL) return;

        prev->next = temp->next;
        delete temp;
    }
}

void Delete_Place(Node** head_ref, int posi)
{
    if(*head_ref == NULL)
    {
        return;
    }
    Node*temp = *head_ref;
    if(posi == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for(int i =0; temp!=NULL && i < posi - 1; i++)
    {
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL)
    {
        return;
    }
    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void Delelte_Whole_List(Node** head_ref)
{
    Node* curr = *head_ref;
    Node* next = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *head_ref = NULL;
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
    cout<<"THE FINAL LINKED LIST IS :"<<endl;
    Printlist(head);
    Delete_element(&head, 22);
    Printlist(head);
    Delete_Place(&head, 2);
    Printlist(head);
    Delelte_Whole_List(&head);
    Printlist(head);
    return 0;
}