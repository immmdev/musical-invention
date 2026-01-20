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

void rightSideView(Node* root, int level, vector<int>&res){
    if(root==NULL) return;

    if(level==res.size()) res.push_back(root->data);

    rightSideView(root->right,level+1,res);
    rightSideView(root->left,level+1,res);
}

void leftSideView(Node* root, int level, vector<int>&res){
    if(root==NULL) return;

    if(level==res.size()) res.push_back(root->data);
    leftSideView(root->left,level+1,res);
    leftSideView(root->right,level+1,res);
}


int main(){
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    //       /     / \
    //      8     9  10
    //       \
    //        11
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->right->left = new Node(8);
    root->left->right->left->right = new Node(11);

    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    vector<int>res;
    leftSideView(root,0,res);

    for(auto x : res){
        cout<<x<<" ";
    }
}