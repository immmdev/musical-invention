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

bool symmetricalHelp(Node* left, Node* right){
 if(left==NULL || right==NULL){
    return left==right;
 }
 if(left->data!=right->data) return false;
 return symmetricalHelp(left->left,right->right) && symmetricalHelp(left->right,right->left);
}

bool isSymmetrical(Node* root){
    return root==NULL || symmetricalHelp(root->left,root->right);

}


int main(){

}