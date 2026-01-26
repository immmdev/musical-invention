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

int cielNode(Node* root,int key){
    int ans=-1;
    while(root!=NULL){
        if(root->data>=key){
            ans=root->data;
            root=root->left;
        } else {
            root=root->right;
        }
    }
    return ans;
}

int floorNode(Node* root, int x){
    int ans=-1;
    while(root!=NULL){
        if(root->data<=x){
            ans=root->data;
            root=root->right;
        } else {
            root=root->left;
        }
    }
    return ans;
}

int main(){

}