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

void markParents(Node *root, map<Node *, Node *> &marked_parnets)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *currNode = q.front();
        q.pop();
        if (currNode->left)
        {
            marked_parnets[currNode->left] = currNode;
            q.push(currNode->left);
        }
        if (currNode->right)
        {
            marked_parnets[currNode->right] = currNode;
            q.push(currNode->right);
        }
    }
}

vector<int> nodesDistanceK(Node *root, int target, int k)
{
    vector<int>ans;
    map<Node *, Node *> marked_parnets;
    markParents(root, marked_parnets);
    map<int, bool> visited;
    queue<Node *> q;

    Node* targetNode=NULL;
    queue<Node*>qq;
    qq.push(root);
    while (!qq.empty()){
        Node* node=qq.front();
        qq.pop();
        if(node->data==target) {
            targetNode=node;
            break;
        }

        if (node->left)  qq.push(node->left);
    if (node->right) qq.push(node->right);

    }

    q.push(targetNode);
    visited[target] = true;
     int level = 0;
    while (!q.empty())
    {
        int n = q.size();
       
        if (level == k)
            break;
        for (int i = 0; i < n; i++)
        {
            Node *currNode = q.front();
            q.pop();
            if (currNode->left && !visited[currNode->left->data])
            {
                q.push(currNode->left);
                visited[currNode->left->data] = true;
            }
            if (currNode->right && !visited[currNode->right->data])
            {
                q.push(currNode->right);
                visited[currNode->right->data] = true;
            }
            if (marked_parnets[currNode] && !visited[marked_parnets[currNode]->data])
            {
                q.push(marked_parnets[currNode]);
                visited[marked_parnets[currNode]->data] = true;
            }
        }
        level++;
    }
   
    while (!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }

    return ans;
}

int main()
{
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

    
    for(auto x:nodesDistanceK(root,5,2)){
        cout<<x<<" ";
    }
   
}