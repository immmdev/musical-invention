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


// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Helper function that computes the maximum sum of a path that starts at 'root'
// and goes downwards (to either left or right). While doing so it updates 'maxi'
// to be the maximum path sum found anywhere in the tree (the path may pass
// through the current node and include both children).
int maxPathDown(Node* root, int &maxi){
    if(root==NULL) return 0; // empty node contributes 0 to a downward path

    // Compute the maximum downward sums from left and right subtrees.
    // If a subtree contributes a negative sum, treat it as 0 (ignore that branch),
    // because any negative contribution would reduce the path sum.
    int leftsum=max(0,maxPathDown(root->left,maxi));
    int rightsum=max(0,maxPathDown(root->right,maxi));

    // max path that uses the current node as the highest node (i.e., passes
    // through root and possibly includes both children)
    maxi=max(maxi,leftsum+rightsum+root->data);

    // Return the maximum sum of a path that starts at current node and goes
    // down to one of its children. This value is used by the parent calls.
    return max(leftsum,rightsum)+root->data;
}
    
// Wrapper that initializes the global maximum and starts recursion.
// Returns the maximum path sum for the whole tree.
int findMaxSum(Node *root) {
        int maxi=INT_MIN;           // start with the smallest possible value
        maxPathDown(root,maxi);     // fills 'maxi' with the correct maximum
        return maxi;
}


int main(){

    return 0;
}