#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
class linked_list {
public:
    Node *head;
    int size;
    linked_list();
    bool isEmpty();
    void insertFirst(int newValue);
    void display();
    int  count();
    bool isFound(int item);
    void insertBefore(int item,int newvalue);
    void Append(int item);
    void Delete(int item);

};
//==================================================================
linked_list::linked_list() {
    head=NULL;
    size=0;
}
//==================================================================
bool linked_list::isEmpty() {
    return (head==NULL);
}
//==================================================================
void linked_list::insertFirst(int newValue) {
    Node* newNode = new Node;
    newNode->data=newValue;
    if(isEmpty())
    {
        newNode->next=NULL;
        head =newNode;
    }
    else
    {
        newNode->next=head;
        head=newNode;
    }
}
//==================================================================
void linked_list::display() {
    Node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
}
//==================================================================
int linked_list::count() {

    return size;
}
//==================================================================
bool linked_list::isFound(int item) {
    Node *temp=head;
    while (temp!=NULL)
    {
        if(item==temp->data)
        {
            return true;
        }
        temp=temp->next;
    }
    return  false;
}
//==================================================================
void linked_list::insertBefore(int item, int newvalue) {
    if(isEmpty())
    {
        insertFirst(newvalue);
    }
    if(!isFound(item)){
        cout<<"the item not found";
        return;
    }
    Node *newNode=new Node();
    newNode->data=newvalue;
    Node *temp=head;
    while (temp!=NULL&&temp->next->data!=item)
    {
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
//==================================================================
void linked_list::Append(int item) {
    if(isEmpty())
    {
        insertFirst(item);
        return;
    }
    Node *temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node *newNode=new Node();
    newNode->data=item;
    temp->next=newNode;
    newNode->next=NULL;
}
//==================================================================
void linked_list::Delete(int item) {
    if(isEmpty())
    {
        cout<<"list is empty ";
        return;
    }
    Node *delPtr=head;
    if(head->data==item)
    {
        head=head->next;
        delete delPtr;
        return;
    }
    delPtr=head;
    Node *prev=NULL;
    while (delPtr->data!=item)
    {
        prev=delPtr;
        delPtr=delPtr->next;
    }
    prev->next=delPtr->next;
    delete delPtr;
}
//====================================================================
int main() {
     linked_list list;
     int n=3;
    while (n--)
    {
        cout<<"please enter your item\n";
        int m;cin>>m;
        list.insertFirst(m);
        list.display();
    }
     list.Append(50);
    list.display();
}
