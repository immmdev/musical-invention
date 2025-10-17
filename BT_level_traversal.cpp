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

// level traversal
vector<vector<int>>leveltraversal(Node* root){
    vector<vector<int>>ans;
    queue<Node*>q;
    // push initially the root of the tree
    q.push(root);
    while(!q.empty()){ // traverse till queue is not empty
        int size=q.size();
        vector<int>level; // for storing level wise elements
        // it will run for the till no. of element in current level
        for(int i=0; i<size; i++){
            Node* req=q.front();
            q.pop(); // removing element one by one
            // pushing element of the next level
            if(req->left) q.push(req->left);
            if(req->right) q.push(req->right);
            level.push_back(req->data);
        }
        // push each level in ans
        ans.push_back(level);
    }
    return ans;
}


int main(){

}