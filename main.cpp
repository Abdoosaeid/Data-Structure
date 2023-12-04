#include <iostream>
using namespace std;
 struct node{
     int data;
     node *next;
     node *prev;
 };
 struct node* head=NULL;
 struct node*tail=NULL;
 //////////////////////////////////////////////////////////////////////////
 void insertFirst(int val)
 {
    node  *newnode=new node;
     newnode->data=val;
    if(head==NULL)
    {
        head=newnode;
        newnode->prev=NULL;
        newnode->next=NULL;
        newnode->data=val;
        tail=newnode;
    }
    else
    {
        newnode->next=head;
        newnode->prev=NULL;
        head->prev=newnode;
        head=newnode;
    }
 }
//////////////////////////////////////////////////////////////////////////
 void insert_last(int val)
 {
     struct node*newnode=new node;
     newnode->data=val;
     if(head==NULL)
     {
         head=newnode;
         newnode->next=NULL;
         newnode->prev=NULL;
         tail=newnode;
     }
     else
     {
         newnode->next= nullptr;
         newnode->prev=tail;
         tail->next=newnode;
         tail=newnode;
     }
 }
//////////////////////////////////////////////////////////////////////////

 void insertAfter(int after,int element)
 {
     node *newnode=new node;
     node*temp=head;
     if(head== nullptr)
     {
         cout<<"the list is empty";
     }
     // if there is one elment
     if (head==tail)
     {
         if(head->data!=after)
         {
             cout<<"the numer you want insert After is not exist";
             return;
         }
         newnode->data=element;
         newnode->prev=head;
         head->next=newnode;
         newnode->next= nullptr;
         tail=newnode;
         return;
     }
     if(tail->data==after)
     {
         newnode->next=NULL;
         newnode->prev=tail;
         tail->next=newnode;
         tail=newnode;
         return;
     }
     while (temp->data!=after)
     {
         temp=temp->next;
         if(temp==NULL)
         {
             cout<<"the numer you want insert After is not exist";
             return;
         }
     }
     newnode->next=temp->next;
     newnode->prev=temp;
     temp->next->prev=newnode;
     newnode->data= element;
     temp->next=newnode;
 }
//////////////////////////////////////////////////////////////////////////

 void deleteFirst(){
     if(head== nullptr)
     {
         return;
     }
     //there is one element
     if (head==tail)
     {
         node *temp;
         temp=tail;
         tail=head= nullptr;
         delete temp;
         return;
     }
     else
     {
         node *temp;
         temp=head;
         head=head->next;
         head->prev= nullptr;
         delete temp;
     }
 }
//////////////////////////////////////////////////////////////////////////

 void deletlast()
 {
     if(head== nullptr)
     {
         return;
     }
     if (head==tail)
     {
         node *temp;
         temp=tail;
         tail=head= nullptr;
         delete temp;
         return;
     }
     else
     {
         node *temp;
         temp=tail;
         tail=tail->prev;
         head->next= nullptr;
         delete temp;
     }
 }
//////////////////////////////////////////////////////////////////////////

 void deletItem(int element) {
     node *temp = head;
     if (head == nullptr) {
         return;
     }
     if (tail == head) {
         if (head->data != element) {
             cout << "could not delete" << endl;
             return;
         }
         head = nullptr;
         tail = nullptr;
         delete temp;
         return;
     }
     if (head->data = element) {
         head = head->next;
         head->prev = nullptr;
         delete temp;
         return;
     }
     if (tail->data == element) {
         temp = tail;
         tail = tail->prev;
         tail->next = nullptr;
         delete temp;
         return;
     }
     while (temp->data != element) {
         temp = temp->next;
         if (temp == NULL) {
             cout << "element not found" << endl;
             return;
         }
     }
     temp->prev->next = temp->next;
     temp->next->prev = temp->prev;
     delete temp;

 }
//////////////////////////////////////////////////////////////////////////

 struct node*search(int element)
 {
     node*temp=head;
     while (temp!= nullptr)
     {
         if(temp->data==element)
         {
             return temp;
             break;
         }
         temp=temp->next;
     }
     return nullptr;
 }
//////////////////////////////////////////////////////////////////////////

void printList()
{
    struct node* temp;
    temp=head;
    while(temp!=NULL)
    {
       cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"\n";
}
//////////////////////////////////////////////////////////////////////////
void printReverse()
{
    struct node* temp;
    temp=tail;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->prev;
    }
    cout<<endl;
}
//////////////////////////////////////////////////////////////////////////
void makereverse()
{
    struct node* prv=NULL;
    struct node* cur=head;
    struct node* nxt;
    while(cur!=NULL)
    {
        nxt=cur->next;
        cur->next=prv;
        prv=cur;
        cur=nxt;
    }
    head=prv;
}
//////////////////////////////////////////////////////////////////////////
int main() {
    insertFirst(5);
    insertFirst(4);
    insertFirst(3);

    printList();
}
