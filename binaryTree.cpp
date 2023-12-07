#include <iostream>
using namespace std;
//create Node
class Node {
public:
    int value;
    Node *left= nullptr ;
    Node *right= nullptr ;
    Node(int item)
    {
        value=item;
    }
};
//create binary search tree
class BST{
public:
    Node *root;
    BST(){root = nullptr;}
    Node *insert(Node *node ,int item);
    void insert(int item);
    void preorder(Node *node);
    void inorder(Node *node);
    void postorder(Node *node);
    Node*search(Node*node,int key);
    bool search(int key);
    Node *FindMin(Node *node);
    Node *FindMax(Node *node);
    Node *Delete(Node *node,int key);
};
//insert in binary search tree
Node *BST::insert(Node *node, int item) {
    if(node== nullptr)
    {
        Node *newnode=new Node(item);
        node=newnode;

    }
    else if(item<node->value)
    {
        node->left= insert(node->left,item);
    }
    else
    {
         node->right= insert(node->right,item);
    }
    return node;
}
void BST::insert(int item)
{
    root= insert(root,item);
}
//BTS preorder traverse
void BST::preorder(Node *node) {
    if(node == nullptr)
        return;
    cout<<node->value<<" ";
    preorder(node->left);
    preorder(node->right);
}
//BTS  inorder traverse
void BST::inorder(Node *node) {
    if(node == nullptr)
        return;
    inorder(node->left);
    cout<<node->value<<" ";
     inorder(node->right);
}
//BTS  postorder traverse
void BST::postorder(Node *node) {
    if(node == nullptr)
        return;
    inorder(node->left);
    inorder(node->right);
    cout<<node->value<<" ";
}
//BST Search
Node* BST::search(Node *node, int key) {
    if(node== nullptr)
        return nullptr;
    else if(node->value==key)
        return node;
    else if(key<node->value)
    {
        node =search(node->left,key);
    }
    else
    {
        node = search(node->right,key);
    }
    return node;
}
bool BST::search(int key) {
    return search(root,key);
}
//find minimum
Node* BST::FindMin(Node *node) {
    if(node== nullptr)
        return nullptr;
    else if(node->left== nullptr)
        return node;
    else
    {
        return FindMin(node->left);
    }
}
//find maximum
Node* BST::FindMax(Node*node) {
    if(node== nullptr)
        return nullptr;
    else if(node->right== nullptr)
        return node;
    else
    {
        return FindMin(node->right);
    }
}
//Delete from BST
Node *BST::Delete(Node *node, int key) {
    if(node== nullptr)
        return nullptr;
    if(key<node->value)
        node->left= Delete(node->left,key);
    else if(key>node->value)
        node->right= Delete(node->right,key);
    else
    {
        //leaf node
        if(!node->right&&!node->left)
        {
            node= nullptr;
        }
        else if(node->left&&!node->right)//there is one child on the left
        {
            node->value=node->left->value;
            delete node->left;
            node->left= nullptr;
        }
        else if(!node->left&&node->right)//there is one child on the right
        {
            node->value=node->right->value;
            delete node->right;
            node->right= nullptr;
        }
        else //there are two children
        {
            Node *max= FindMax(node->left);
            node->value=max->value;
            node->left= Delete(node->left,max->value);
        }
    }
    return node;
}

int main() {
    //try create
    BST tree;
    //try insert
    tree.insert(45);
    tree.insert(15);
    tree.insert(79);
    tree.insert(90);
    tree.insert(10);
    tree.insert(55);
    tree.insert(12);
    tree.insert(20);
    tree.insert(50);
    //try traverse
    tree.inorder(tree.root);//10 12 15 20 45 50 55 79 90
    cout<<"\n";
    tree.preorder(tree.root);//45 15 10 12 20 79 55 50 90
    cout<<"\n";
    tree.postorder(tree.root);//10 12 15 20 50 55 79 90 45
    cout<<"\n";
    //try search
    cout<<tree.search(50)<<"\n";//1
    cout<<tree.search(7)<<"\n";//0
    //try FindMax
    cout<<tree.FindMax(tree.root)->value<<"\n";//50
    //try FindMin
    cout<<tree.FindMin(tree.root)->value<<"\n";//10
    //try delete
    tree.Delete(tree.root,15);
    tree.inorder(tree.root);//10 12 20 45 50 55 79 90
}
