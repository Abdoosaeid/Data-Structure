#include <iostream>
#define max 20
using namespace std;
class Circular_Queue
{
private:
    int items[max];
    int front,rear;
public:
    Circular_Queue();
    bool is_empty();
    bool is_full();
    void insert (int item);
    int remove();
    int size();
    void display();
};
Circular_Queue::Circular_Queue() {
    front=-1;
    rear=-1;
}
bool Circular_Queue::is_empty() {
    return front==-1;
}
bool Circular_Queue::is_full() {
    return ((front==0&&rear==max-1)||front==rear+1);
   //or => return (front==(rear+1)%max);
}
void Circular_Queue::insert(int item) {
    if(is_full())
    {
        cout<<"error : the queue is overflow";
        return;
    }
    if (is_empty())
    {
        rear=0,front=0;
    }
    else
    {
        rear=(rear+1)%max;
    }
    items[rear]++;
}
int Circular_Queue::remove() {
    if (is_empty())
    {
        cout<<"Error : the queue is underflow";
        return -1;
    }
    else {
        int item = items[front];
        if (front == rear) {
            front = -1, rear - 1;
        } else {
            front = (front + 1) % max;
        }
        return item;
    }
}
void Circular_Queue::display() {
    if (!is_empty())
    {
        if(front<=rear)
        {
            for (int i = front; i <= rear; ++i) {
                cout<<items[i]<<" ";
            }
        }
        else
        {
            for (int i = front; i < max; ++i) {
                cout<<items[i]<<" ";
            }
            for (int i = 0; i <= rear; ++i) {
                cout<<items[i]<<" ";
            }
        }
        cout<<endl;
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
