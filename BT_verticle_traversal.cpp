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

// TC - O(Nlog(N))
// SC - O(N)
vector<vector<int>>verticleTraversal(Node* root){
    vector<vector<int>>ans;
    if(root==NULL) return ans;
    // {node,{verticle,level}}
    queue<pair<Node*,pair<int,int>>>todo;
    todo.push({root,{0,0}});
    // {verticle->{level1->data1,level2->data2,...},...}
    map<int,map<int,multiset<int>>>nodes;
    while(!todo.empty()){
        // take out first thing in the queue
        auto p=todo.front();
        // extract the node
        Node* node=p.first;
        // remove first thing
        todo.pop();
        // extracting the cordinates of the multiset where the node data will stored 1 by 1
        auto x=p.second.first;
        auto y=p.second.second;
        // store the data at that cordinate in the form of multiset
        nodes[x][y].insert(node->data);
        // move to left if exist and decrease verticle by 1 and increse level by 1
        if(node->left) todo.push({node->left,{x-1,y+1}});
        // move to left if exist and increase verticle by 1 and increase level by 1
        if(node->right) todo.push({node->right,{x+1,y+1}});
    }
    // now you have mapped all the nodes at the their cordinates like {verticle1->{level1->{data1},level2->{data0,data1},...},...}
    // now extract data from the multiset vertically 
    // travering all nodes stored in map each node.first is a verticle cordinate
    for(auto px : nodes){
        vector<int>col;
        // py is another map having level->multiset
        for(auto py : px.second){
            // py.second is actually multiset traversing set and insertinga data in the vector
            for(auto val : py.second){
                col.push_back(val);
            }
        }
        // after each verticle push col into ans...
        ans.push_back(col);
    }

    return ans;

}

// approch assigning elements (x,y) (verticle,level) no.
// then mapping it into an mapp

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
    auto ans=verticleTraversal(root);
    for(auto x: ans){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}