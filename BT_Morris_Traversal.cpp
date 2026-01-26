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

vector<int> morristraversal(Node *root)
{
    vector<int> inorder;
    if (root == NULL)
        return inorder;
    Node *cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            Node* prev=cur->left;
            while(prev->right && prev->right!=cur){
                prev=prev->right;
            }

            if(prev->right==NULL){
                prev->right=cur;
                cur=cur->left;
            } 
            else {
                prev->right=NULL;
                inorder.push_back(cur->data);
                cur=cur->right;
            }
        }
    }

    return inorder;
}
int main()
{
}