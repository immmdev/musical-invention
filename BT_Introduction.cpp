#include<bits/stdc++.h>
using namespace std;

// A binary tree is a hierarchical tree data structure in which each node can have 0, 1, or 2 child nodes.

// Data (value) — The information stored in the node.

// Left pointer — Points to the left child node.

// Right pointer — Points to the right child node.
class Node{
    public:
        int data;
        Node* left;
        Node* right;

    public:
        Node(int data1,Node* left1, Node* right1){
            data=data1;
            left=left1;
            right=right1;
        }

    public:
        Node(int data1){
            data=data1;
            left=nullptr;
            right=nullptr;
        }
};

int main(){
    Node* root=new Node(1);
    Node* left=new Node(2);
    Node* right=new Node(3);
    root->left=left;
    root->right=right;
    left->right=new Node(5);
}