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

vector<int>bottomView(Node* root){
    vector<int>res;
    if(root==NULL) return res;
    queue<pair<Node*,int>>todo;
    todo.push({root,0});
    map<int,int>nodes;
    while(!todo.empty()){
        auto p=todo.front();
        todo.pop();
        Node* node=p.first;
        int v=p.second;
        nodes[v]=node->data;
        if(node->left) todo.push({node->left,v-1});
        if(node->right) todo.push({node->right,v+1});
    }

    for(auto x : nodes){
        res.push_back(x.second);
    }

    return res;
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

    auto ans=bottomView(root);
    for(auto x: ans){
        cout<<x<<" ";
    }
}