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

//  o(logbase2n)
Node* search(Node* root,int val){
    while(root!=NULL && root->data!=val){
        root=val<root->data?root->left:root->right;
    }
    return root;
}
int main(){
    //         50   ← root
    //        /  \
    //      30    70
    //     /  \   / \
    //   20  40  60  80

    // creating BST manually
    Node* root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(70);

    root->left->left = new Node(20);
    root->left->right = new Node(40);

    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout<<search(root, 80)<<endl;

}