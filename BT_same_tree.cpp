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

// Determine whether two binary trees rooted at p and q are identical
// (same structure and same node values).
bool sameBT(Node* p, Node* q){
    // If both are null, trees match at this branch.
    if (p == nullptr && q == nullptr) return true;
    // If one is null and the other isn't, trees differ.
    if (p == nullptr || q == nullptr) return false;
    // Compare current node values and recurse on children.
    return (p->data == q->data)
        && sameBT(p->left, q->left)
        && sameBT(p->right, q->right);
}
