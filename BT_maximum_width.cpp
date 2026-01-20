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

int maximumWidthBT(Node* root){
    if(!root) return 0;
    // store node,index
    queue<pair<Node*,int>>q;
    int ans=0;
    // initially root is inserted
    q.push({root,0});
    
    while(!q.empty()){
        int first,last;
        int n=q.size();
        int minimum=q.front().second;
        for(int i=0; i<n; i++){
            // normalizing index to prevent overflow
            int curr_id=q.front().second-minimum;
            // creating queue for the next iteration
            Node* currNode=q.front().first;
            q.pop();
            if(i==0) first=curr_id;
            if(i==n-1) last=curr_id;
            if(currNode->left) q.push({currNode->left,2*curr_id+1});
            if(currNode->right) q.push({currNode->right,2*curr_id+2});
        }
        // storing max ans 
        ans=max(ans,last-first+1);

    }

    return ans;

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

    int ans=maximumWidthBT(root);
    cout<<ans<<endl;
}