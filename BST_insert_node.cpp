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

Node* insertNode(Node* root,int key){
    if(root==NULL) return new Node(key);
    Node* temp=root;
    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data<key){
            prev=temp;
            temp=temp->right;
        } else {
            prev=temp;
            temp=temp->left;
        }
    }
    if(prev->data>key){
        prev->left=new Node(key);
    } else {
        prev->right=new Node(key);
    }
    return root;
}

int main(){

}