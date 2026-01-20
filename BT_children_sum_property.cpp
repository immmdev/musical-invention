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

// the root must have value always equal to the sum of the left and right you can increase the value of any node by +1;
// tc-o(n)
// sc-o(h)
void childrenSumProperty(Node* root){
    // base condition
    if(root==NULL) return;

    // updating the root or child values so the while coming up value never sort
    int sum=0;
    if(root->left) {
        sum+=root->left->data;
    }

    if(root->right){
        sum+=root->right->data;
    }

    if(sum>=root->data){
        root->data=sum;
    }

    else {
        if(root->left) {
            root->left->data=sum;
        } else if (root->right) {
            root->right->data=sum;
        }
    }

    // moving to left and right recursively
    childrenSumProperty(root->left);
    childrenSumProperty(root->right);

    // while returning updating root
    int tot=0;
    if(root->left){
        tot+=root->left->data;
    }
    if(root->right){
        tot+=root->right->data;
    }

    if(root->left||root->right){
        root->data=tot;
    }
}

int main(){

}