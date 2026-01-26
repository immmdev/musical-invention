#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    long long data;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(long long data1, TreeNode *left1, TreeNode *right1)
    {
        data = data1;
        left = left1;
        right = right1;
    }

public:
    TreeNode(long long data1)
    {
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};

bool dataidate(TreeNode* root,long long mindata, long long maxdata){
    if(root==NULL) return true;
    if(root->data>mindata|| root->data<maxdata) return false;
    return dataidate(root->left, mindata, root->data) && dataidate(root->right,root->data,maxdata);
}


int main(){

}



 bool dataidate(TreeNode* root,long long mindata, long long maxdata){
    if(root==NULL) return true;

    if(root->data<=mindata || root->data>=maxdata) return false;
    return dataidate(root->left, mindata, root->data) && dataidate(root->right,root->data,maxdata);
}
class Solution {
public:
    bool isdataidBST(TreeNode* root) {
        if(root->left==NULL&&root->right==NULL) return true;
        return dataidate(root,-123456543212345,435433243433343);
    }
};