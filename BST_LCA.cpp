#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    long long data;
    Node *left;
    Node *right;

public:
    Node(long long data1, Node *left1, Node *right1)
    {
        data = data1;
        left = left1;
        right = right1;
    }

public:
    Node(long long data1)
    {
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};

// TC O(N)
// SC O(N)
int LCA(Node* root, Node* n1, Node* n2){
    if(root==NULL) return 0;
    Node* temp=root;
    if(n1->data > root->data && n2->data > root->data){
        temp=temp->right;
    }
    else if(n1->data < root->data && n2->data < root->data){
        temp=temp->left;
    }
    else {
        return temp->data;
    }

}


int main(){

}