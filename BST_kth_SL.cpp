#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(int val1, TreeNode *left1, TreeNode *right1)
    {
        val = val1;
        left = left1;
        right = right1;
    }

public:
    TreeNode(int val1)
    {
        val = val1;
        left = nullptr;
        right = nullptr;
    }
};

int kthSmallest(TreeNode *root, int k)
{
    if (root == NULL)
        return 0;
    int cnt = 0;
    TreeNode *cur = root;
    int ans = 0;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            cnt++;
            ans = cur->val;
            if (cnt == k)
            {
                return ans;
            }
           
            cur = cur->right;
        }
        else
        {
            TreeNode *prev = cur->left;
            while (prev->right && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }

            else
            {
                prev->right = NULL;
                cnt++;
                ans = cur->val;
                if (cnt == k)
                {
                    return ans;
                }
               
                cur=cur->right;
            }
        }
    }
    return ans;
}

int main()
{
    
}