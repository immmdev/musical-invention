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

// (root left right)
// TC O(N)
// SC O(N)
void preorder(Node* root,vector<int>&res){
    // base case if reaches null
    if(root==NULL) return;
    // print data in root at every node 
    res.push_back(root->data);
    // move to its left subtree recursively and continue printing root data
    preorder(root->left,res);
    // after left sub tree is executed then the right sub tree is
    preorder(root->right,res);
    
}

// (left root right)
// TC O(N)
// SC O(N)
void inorder(Node* root, vector<int>&res){
    // base case
    if(root==NULL) return;
    // traverse left subtree
    inorder(root->left,res);
    // print data
    res.push_back(root->data);
    // traversing right subtree
    inorder(root->right,res);
}

// (left right root)
// TC O(N)
// SC O(N)
void postorder(Node* root, vector<int>&res){
    // base case
    if(root==NULL) return;
    // traverse left subtree
    postorder(root->left,res);
    // traversing right subtree
    postorder(root->right,res);
    // print data
    res.push_back(root->data);
}

// iterative preorder (root left right)
void iterativepreorder(Node* root, vector<int>&res){

    stack<Node*>st;
    st.push(root);
    // iterate till stack is not empty
    while(!st.empty()){
        Node* top=st.top();
        st.pop();
        res.push_back(top->data);
        // pushing data into satck  for next iteration
        if(top->right) st.push(top->right);
        if(top->left) st.push(top->left);  
    }
}

// iterative inorder
void iterativeinorder(Node* root,vector<int>&res){
    stack<Node*>st;
    Node* node=root;
    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        } else {
            if(st.empty()==true) break;
            node=st.top();
            st.pop();
            res.push_back(node->data);
            node=node->right;
        }
    }
}

// iterative postorder
void iterativepostorder(Node* root, vector<int>&res){
    stack<Node*>st1;
    stack<int>st2;
    st1.push(root);
    // repeact till st1 iss not empty
    while(!st1.empty()){
        Node* top=st1.top();
        st1.pop();
        // push tree left right (children) in the st1
        if(top->left) st1.push(top->left);
        if(top->right) st1.push(top->right);
        // push data in st2 
        st2.push(top->data);
    }

    while(!st2.empty()){
        res.push_back(st2.top());
        st2.pop();
    }

}
int main(){
    // Create binary tree
    //       1
    //      /  \
    //    2     3
    //   / \     \
    //  4   5     6
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    vector<int>res;
    // iterativepreorder(root,res);
    iterativepostorder(root,res);
    // postorder(root,res);
    for(auto it:res){
        cout<<it<<" ";
    }
    // Output:- 1 2 4 5 3 6

}