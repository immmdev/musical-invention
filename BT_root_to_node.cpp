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

// Function to find path from root to a specific node
// Parameters: root - pointer to root node, x - target node value, arr - vector to store the path
// Returns: true if path found, false otherwise
bool rootToNodePath(Node* root, int x, vector<int>&arr){
    // Base case: if root is null, path doesn't exist
    if(!root) return false;

    // Add current node's data to the path
    arr.push_back(root->data);

    // If current node is the target node, path found
    if(root->data==x) return true;

    // Recursively search in left subtree or right subtree
    // If either subtree contains the target node, return true
    if(rootToNodePath(root->left,x,arr)||rootToNodePath(root->right,x,arr)){
        return true;
    }

    // Backtrack: remove current node from path if target not found in its subtrees
    arr.pop_back();
    return false;
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

    vector<int>res;

    rootToNodePath(root,9,res);
    for(auto x:res){
        cout<<x<<" ";
    }
}