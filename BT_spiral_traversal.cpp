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


// Complexity:
// Time: O(N), where N is the number of nodes, since each node is
//       visited and processed exactly once.
//  Space: O(N) worst-case for the output plus O(W) auxiliary space for
//       the queue and temporary per-level vector, where W is the maximum
//     number of nodes at any single level (tree width).
 

vector<vector<int>> spiralTraversal(Node* root){
    // Result container: each element is one level's values in spiral order
    vector<vector<int>> ans;

    // Early exit for empty tree
    if(root == NULL) return ans;

    // Queue for BFS (level-order traversal)
    queue<Node*> tq;
    tq.push(root); // start from root

    // Direction flag: true => fill left-to-right, false => fill right-to-left
    bool isLeftRight = true;

    // Process level by level until queue is exhausted
    while(!tq.empty()){
        int n = tq.size();          // number of nodes at current level
        vector<int> row(n);         // temporary vector to hold current level values

        // Iterate over all nodes in this level
        for(int i = 0; i < n; i++){
            // Decide index to write into based on current direction
            int index = isLeftRight ? i : (n - 1 - i);

            // Pop next node from queue
            Node* node = tq.front();
            tq.pop();

            // Place node value at computed index to achieve zigzag ordering
            row[index] = node->data;

            // Enqueue children in normal left->right order for next level
            if(node->left)  tq.push(node->left);
            if(node->right) tq.push(node->right);
        }

        // Toggle direction for the next level
        isLeftRight = !isLeftRight;

        // Append completed level to the answer
        ans.push_back(row);
    }

    return ans;
}
vector<vector<int>>spiralTraversal(Node* root){
    vector<vector<int>>ans;
    if(root==NULL) return ans;
    queue<Node*>tq;
    tq.push(root);
    bool isLeftRight=true;
    while(!tq.empty()){
        int n=tq.size();
        vector<int>row(n);
        for(int i=0; i<n; i++){
            int index=isLeftRight? i : n-1-i;
            Node* node=tq.front();
            tq.pop();
            row[index]=node->data;
            if(node->left) tq.push(node->left);
            if(node->right) tq.push(node->right);
        }
        isLeftRight=!isLeftRight;
        ans.push_back(row);
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    vector<vector<int>> ans=spiralTraversal(root);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<< " ";
        }
        cout<<endl;
    }
    return 0;
}