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

void markParentPointers(Node *root, map<Node *, Node *> &markParent)
{
    if (root == NULL)return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *currNode = q.front();
        q.pop();

        if (currNode->left)
        {
            markParent[currNode->left] = currNode;
            q.push(currNode->left);
        }
        if (currNode->right)
        {
            markParent[currNode->right] = currNode;
            q.push(currNode->right);
        }
    }
}

int timeBurningBT(Node *root, Node *node)
{
    map<Node *, Node *> markParent;
    markParentPointers(root, markParent);
    queue<Node *> q;
    map<Node *, bool> visited;
    q.push(node);
    visited[node]=true;
    int time = 0;
   
    while (!q.empty())
    {
        int n = q.size();
        bool burned=false;
        for (int i = 0; i < n; i++)
        {
            Node *currNode = q.front();
            q.pop();
            if (currNode->left && !visited[currNode->left])
            {
                q.push(currNode->left);
                visited[currNode->left]=true;
                burned=true;
            }
            if (currNode->right && !visited[currNode->right])
            {
                q.push(currNode->right);
                visited[currNode->right]=true;
                 burned=true;
            }
            if(markParent[currNode] && !visited[markParent[currNode]]){
                visited[markParent[currNode]]=true;
                q.push(markParent[currNode]);
                 burned=true;
            }
        }
        if(burned)time++;
    }
    return time;
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
        cout<<timeBurningBT(root,root)<<endl;
    }