#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node*next;
    Node()
    {
        data=0;
        next= nullptr;
    }
};

class queue {
public:
    Node *front;
    Node *rear;
    queue(){
        front=rear= nullptr;
    }
    void enqueue(int value);
    void dequeue();
    int getFront();
    int getRear();
    bool isEmpty();
    bool isFull();
    void Clear();
    void Traverse();
    int Count();
    void display();
    bool Search(int val);
};

void queue::display() {
    Node *temp;
    temp=front;
    while (temp!= nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
bool queue::isEmpty() {
    if (front== nullptr)
    {
        return false;
    }
    return true;
}
///////////////////////////////////////////
void queue::enqueue(int value) {
    Node *newNode=new Node;
    newNode->data=value;
    if (isEmpty())
    {
        front=rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
}
///////////////////////////////////////////
void queue::Traverse() {
    Node*temp=front;
    while (temp!= nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
///////////////////////////////////////////
void queue::dequeue() {
    if(isEmpty())
    {
        cout<<"the queue is empty";
    } else if(front==rear)
    {
        free(front);
        front=rear= nullptr;
    }
    else
    {
        Node *delptr=front;
        front=front->next;
        delete delptr;
    }
}
///////////////////////////////////////////
int queue::getFront() {
    return front->data;
}
///////////////////////////////////////////
int queue::getRear() {
    return rear->data;
}
///////////////////////////////////////////
int queue::Count() {
    Node*temp=front;
    int count(0);
    while (temp!= nullptr)
    {
        count++;
        temp=temp->next;
    }
}
int main() {
    queue q;
    while(1)
    {
        printf("1. Enqueue 2. Dequeue 3. Size 4. Print 5. Top 6. Exit\n");
        int choice;
        cout<<"enter choice: ";
        cin>>choice;
        if(choice==1)
        {
            int x;
            cout<<"enter element: ";
            cin>>x;
            q.enqueue(x);
            q.display();
        }
        else if(choice==2)
        {
            if(q.Count()>0)
            {
                q.dequeue();
            }
            else
            {
                cout<<"empty queue"<<endl;
            }
        }
        else if(choice==3)
        {
            cout<<"size is: "<<q.Count()<<endl;
        }
        else if(choice==4)
        {
            q.display();
        }
        else if(choice==5)
        {
            if(q.Count()==0) cout<<"no element in queue"<<endl;
            else cout<<q.rear<<endl;
        }
        else if(choice==6) return 0;
    }
}
