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

bool isLeafNode(Node* root){
    if(root->left==NULL && root->right==NULL)return true;
    else return false;
}

// left bounday move to left till there is left else move right jut befre the leat node
vector<int> leftBoundary(Node* root,vector<int> &res){
    Node* curr=root->left;
    while(curr){
        if(!isLeafNode(curr))res.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right; 
    }
    return res;
}

// move to the right till there is right else move to left just befor the leaf node
vector<int> RightBoundary(Node* root,vector<int> &res){
    Node* curr=root->right;
    vector<int>temp;
    while(curr){
        if(!isLeafNode(curr)) temp.push_back(curr->data);
        if(curr->right) curr=curr->right;
        else curr=curr->left; 
    }
    for(int i=temp.size()-1; i>=0; i--){
        res.push_back(temp[i]);
    }
    return res;
}

// pushing leaf nodes
vector<int>leafNodes(Node* root,vector<int> &res){
    if(isLeafNode(root)) {
        res.push_back(root->data);
        return res;
    }
    if(root->left) leafNodes(root->left,res);
    if(root->right) leafNodes(root->right,res);
}


// TC-O(H)+O(H)+O(N)
// SC- O(N)auxilary space
vector<int>boundaryTraversal(Node* root){
    vector<int>res;
    if(root==NULL) return res;
    if(!isLeafNode(root)) res.push_back(root->data);
    leftBoundary(root,res);
    leafNodes(root,res);
    RightBoundary(root,res);
    return res;
}

int main(){
    /*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
           /     / \
          8     9  10
*/

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    vector<int>res=boundaryTraversal(root);
    for(auto x: res){
        cout<<x<<" ";
    }
}