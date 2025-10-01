/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *successor = NULL;
        while (root != NULL)
        {
            if (p->val >= root->val)
            {
                root = root->right;
            }
            else
            {
                successor = root;
                root = root->left;
            }
        }
        return successor;
    }

    TreeNode *inorderPredecessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *predecessor = NULL;
        while (root != NULL)
        {
            if (p->val <= root->val)
            {
                root = root->left;
            }
            else
            {
                predecessor = root;
                root = root->right;
            }
        }
        return predecessor;
    }
};