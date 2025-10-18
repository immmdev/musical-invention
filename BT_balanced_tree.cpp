#include<bits/stdc++.h>
using namespace std;

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

// balanced BT
// TC O(N)
// SC O(N)
int balancedBT(Node* root){
    if(root==NULL) return 0;
    // finding height of left subtree
    int lh=balancedBT(root->left);
    // if lh=-1 at any instance it will break here with false
    if(lh==-1) return -1;
    // finding height of the right subtree
    int rh=balancedBT(root->right);
    // if rh=-1 at any instance it will break here with false
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    // returns the height of thr tree
    return 1+max(lh,rh);
}

int main(){
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6); 
}