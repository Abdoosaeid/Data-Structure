#include <iostream>
using namespace std;
class Array {
private:
    int size;
    int length;
    int *items;
public:
    Array(int arr_size);
    void Fill();
    void display();
    int getSize();
    int getLength();
    int search(int key);
    void Append(int newItem);
    void insert(int index,int newitem);
    void Delete(int index);
    void Enlarge(int newSize);
    void marge(Array other);
};

////////////////////////////////////////////////////
Array::Array(int arr_size) {
    size=arr_size;
    length=0;
    //  items= (int*) malloc(arr_size*sizeof(int));
    items=new int [arr_size];
    return;
}
////////////////////////////////////////////////////
void Array::Fill() {
    int no_of_items;
    cout<<"how many items you want to fill?\n";
    cin>>no_of_items;
    if (no_of_items>size)
    {
        cout<<"You cannot exceed the array size\n";
        return;
    }
    for (int i = 0; i < no_of_items; ++i) {
        cout<<"enter item no "<<i+1<<'\n';
        cin>>items[i];
        length++;
    }
    return;
}
/////////////////////////////////////////////////////
void Array::display() {
    for (int i = 0; i < length; ++i) {
        cout<<" item "<<i+1<<"is_";
        cout<<items[i]<<"\n";
    }
    return;
}
/////////////////////////////////////////////////////
int Array::getSize() {
    return size;
}
////////////////////////////////////////////////////
int Array::getLength() {
    return length;
}
///////////////////////////////////////////////////
int Array::search(int key) {
    for (int i = 0; i <length ; ++i) {
        if (items[i]==key)
        {
            return i;
        }
    }
    return -1;
}
//////////////////////////////////////////////////
void Array::Append(int newItem) {
    if(length>=size)
    {
        cout<<"Array is full";
        return;
    }
    items[length]=newItem;
    length++;
}
////////////////////////////////////////////////////
void Array::insert(int index, int newItem) {
    if(length>=size||index>=size||index<0)
    {
        cout<<"Array is full";
        return;
    }
    for (int i = length; i >index ; i--) {
        items[i]=items[i-1];
    }
    items[index]=newItem;
    length++;
}
////////////////////////////////////////////////////
void Array::Delete(int index) {
    if(length==0)
    {
        cout<<"Array is empty";
        return;
    }
    for (int i = index; i <length-1; ++i) {
        items[i]=items[i+1];
    }
    length--;
}
///////////////////////////////////////////////////////
void Array::Enlarge(int newSize) {
    if(newSize<=size)
    {
        cout<<"new size must be larger than the current";
        return;
    }
    realloc(items, newSize*sizeof(int));
    size=newSize;
}
///////////////////////////////////////////////////////
void Array::marge(Array other) {
    size += other.getSize();
    int *old = items;
    items = new int[size];
    int i;
    for (i = 0; i < length; i++) {
        items[i] = old[i];
    }
    delete[]old;
    int j = i;
    for (int k = 0; k < other.length; ++k) {
        items[j++] = other.items[i];
        length++;
    }
}

int main() {
    cout<<"enter the array size";
    int n;cin>>n;
    Array my_Array(n);
    my_Array.Enlarge(7);
   cout<<my_Array.getSize();
   my_Array.Fill();
    return 0;
}
