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

// tc-o(n)
// sc-o(n)


string serialize(Node* root){
    if(root==NULL) return " ";
    queue<Node*>q;
    q.push(root);
    string str=" ";
    while(!q.empty()){
        Node* currNode=q.front();
        q.pop();
        if(currNode==NULL) str.append("#,");
        else str.append(to_string(currNode->data)+',');
        if(currNode!=NULL){
            q.push(currNode->left);
            q.push(currNode->right);
        }

    }
    return str;
}

Node* deselialize(string data){
    if(data.size()==0) return NULL;
    // loads the string into the stream s
    stringstream s(data);
    string num;
    // get the data from the loaded stream till ,
    getline(s,num,',');
    // converting string to integer
    Node* root=new Node(stoi(num));
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* currNode=q.front();
        q.pop();
        getline(s,num,',');
        if(num=="#"){
            currNode->left=NULL;
        } else {
            Node* leftNode=new Node(stoi(num));
            currNode->left=leftNode;
            q.push(leftNode);
        }
        getline(s,num,',');
         if(num=="#"){
            currNode->right=NULL;
        } else {
            Node* rightNode=new Node(stoi(num));
            currNode->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main(){
Node* root = new Node(1);
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    //       /     / \
    //      8     9  10
    //       \
    //        11
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


    cout<<serialize(root)<<endl;

}