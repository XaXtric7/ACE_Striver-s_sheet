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

// 1. Recursive (reverse preorder)

class Solution1
{
public:
    TreeNode *prev = nullptr;

    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};

// 2. Iterative using Stack

class Solution2
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();

            if (cur->right)
                st.push(cur->right);
            if (cur->left)
                st.push(cur->left);

            if (!st.empty())
                cur->right = st.top();
            cur->left = nullptr;
        }
    }
};

// 3. Morris Traversal (O(1) space)

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *cur = root;

        while (cur)
        {
            if (cur->left)
            {
                TreeNode *prev = cur->left;
                while (prev->right)
                {
                    prev = prev->right;
                }

                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};