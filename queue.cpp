#include <iostream>
using namespace std;
#define maxQueue 100
class queue{
private:
    int items[maxQueue];
    int front,rear;
public:
    queue(){
        front=-1,rear=-1;
    }
    void insert(int item);
    int remove();
    bool is_empty();
    bool is_full();
    void display();
    int queueSize();
};
bool queue::is_full() {
    return (front==0&&rear==maxQueue-1);
}
bool queue::is_empty() {
    return (rear==-1&&front==-1);
}
void queue::insert(int item) {
    if (is_full())
    {
        cout<<"Error : the queue is overflow";
        return;
    }
    if(is_empty())
    {
        front++;
    }
    items[++rear]=item;
}
int queue::queueSize(){
    int num = (rear+maxQueue-front)%maxQueue;
    return num;
}
int queue::remove() {
    if (is_empty())
    {
        cout<<"error : the queue is underflow";
        return -1;
    }
    else
    {
        int item =items[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front++;
        }
        return item;
    }
}
void queue::display() {
    cout<<"Queue::";
    if(!is_empty())
    {
        for (int i = front; i <=rear ; ++i) {
            {
                cout << items[i] << " | ";
            }
        }
        cout<<endl;
    }
}
int main() {
    int option, n, value,siz;
    queue q;
    do
    {
        cout << "\n 1.Insert an element in queue";
        cout << "\n 2.Delete an element from queue";
        cout << "\n 3.Display queue";
        cout << "\n 4.Queue Size";
        cout << "\n 5.Quit";
        cout << "\n Enter your choice: ";
        cin >> option;
        switch(option){
            case 1:
                cout << "\n Enter element: ";
                cin >> n;
                q.insert(n);
                break;
            case 2:
                value = q.remove();
                break;
            case 3:
                q.display();
                break;
            case 4:
                siz=q.queueSize();
                cout<<"Size of Queue is "<<siz<<endl;
                break;
            case 5:
                return 0;
        }
    }
    while(option!=-1);
    return 0;

}
