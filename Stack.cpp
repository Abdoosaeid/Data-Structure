#include <iostream>
#define max_size 100
using namespace std;
class stack {
private:
    int items[max_size];
    int top;
public:
    stack(){top=-1;}
    void push(int item);
    int pop();
    bool is_empty();
    bool is_full();
    void print_all_elements();
};

void stack::push(int item) {
    if(is_full())
    {
        cout<<"the stack is over flow";
        exit(-1);
    }
    items[++top]=item;
}

int stack::pop() {
    if(is_empty())
    {
        cout<<"the stack is underflow";
        exit(-1);
    }
    int temp=items[top--];
    return temp;
}

bool stack::is_empty()
{
    return top==-1;
};
bool stack::is_full() {
    return top==max_size-1;
}
void stack::print_all_elements() {
    for (int i = 0; i <= top; ++i) {
        cout<<items[i]<<" ";
    }
}
int main() {

    stack s1;

    while(1)
    {
        cout<<"\n1.PUSH\n2.POP\n3.DISPLAY\n";
        int s;
        cout<<"Enter your choice: ";
        cin>>s;

        switch(s)
        {
            case 1:
                int a;
                cin>>a;
                s1.push(a);
                system("cls");
                break;
            case 2:
                system("cls");
                s1.pop();
                break;
            case 3:
                s1.print_all_elements();
                break;
            default:
                cout<<"Invalid choice";
        }
    }
}
