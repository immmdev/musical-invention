#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int data1, Node *left1, Node *right1)
    {
        data = data1;
        left = left1;
        right = right1;
    }

public:
    Node(int data1)
    {
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};

int leftHeight(Node* root){
    if(root==NULL) return 0;
    int h=0;
    while(root){
        h++;
        root=root->left;
    }   
    return h;
}

int rightHeight(Node* root){
    if(root==NULL) return 0;
    int h=0;
    while(root){
        h++;
        root=root->right;
    }   
    return h;
}

int nodesCompleteBT(Node* root){
    if(root==NULL) return 0;
    int lh=leftHeight(root);
    int rh=rightHeight(root);
    if(lh==rh){
        return (1<<lh)-1;
    }
    return 1+ nodesCompleteBT(root->left) + nodesCompleteBT(root->right);
}

int main(){
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    //       
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);



    // root->right->right->left = new Node(9);
    // root->right->right->right = new Node(10);

    cout<<nodesCompleteBT(root)<<endl;
}