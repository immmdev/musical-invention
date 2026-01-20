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

bool pathToNode(Node* root, int x, vector<int>&arr){
    if(!root) return false;

    arr.push_back(root->data);

    if(root->data==x) return true;

    if(pathToNode(root->left,x,arr)||pathToNode(root->right,x,arr)){
        return true;
    }

    arr.pop_back();
    return false;
}

// optimised
Node* LCA(Node* root, Node* a, Node* b){
    if(root==NULL || root==a || root==b) return root;
    Node* left=LCA(root->left,a,b);
    Node* right=LCA(root->right,a,b);

    if(left==NULL) return right;
    else if(right==NULL) return left;
    else return root;
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
    // brute force
    vector<int>p1;
    vector<int>p2;
    pathToNode(root,4,p1);
    pathToNode(root,11,p2);
    int n1=p1.size();
    int n2=p2.size();
    int n=n1>n2?n1:n2;
    int ans=-1;
    for(int i=0; i<n; i++){
        if(p1[i]==p2[i]) ans=p1[i];
        else break;
    }

    cout<<ans<<endl;

    // Node* ans=LCA(root,)
}