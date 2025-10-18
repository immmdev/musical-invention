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

// maximum dimeter means longest path along edges.
// it is not necessary to pass through root.
int Diameter(Node* root,int &maxi){
    if(root==NULL) return 0;
    int lh=Diameter(root->left,maxi);
    int rh=Diameter(root->right,maxi);
    // checking dimeter at every subtree
    maxi=max(lh+rh,maxi);
    return 1+max(lh,rh);
}

int maxi(Node* root) {
    int maxi=0;
    Diameter(root,maxi);
    return maxi;     
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
    cout<<maxi(root)<<endl;
}