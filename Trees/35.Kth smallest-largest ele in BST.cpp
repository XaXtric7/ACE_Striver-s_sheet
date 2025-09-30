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
    int kthSmallest(TreeNode *root, int k)
    {
        TreeNode *cur = root;
        int count = 0;

        while (cur != nullptr)
        {
            if (cur->left == nullptr)
            {
                // visit this node
                count++;
                if (count == k)
                    return cur->val;
                cur = cur->right;
            }
            else
            {
                TreeNode *prev = cur->left;
                while (prev->right != nullptr && prev->right != cur)
                {
                    prev = prev->right;
                }
                if (prev->right == nullptr)
                {
                    // make thread
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    // remove thread and visit
                    prev->right = nullptr;
                    count++;
                    if (count == k)
                        return cur->val;
                    cur = cur->right;
                }
            }
        }
        return -1; // k not valid
    }

    int kthLargest(TreeNode *root, int k)
    {
        TreeNode *cur = root;
        int count = 0;

        while (cur != nullptr)
        {
            if (cur->right == nullptr)
            {
                // visit this node
                count++;
                if (count == k)
                    return cur->val;
                cur = cur->left;
            }
            else
            {
                TreeNode *prev = cur->right;
                while (prev->left != nullptr && prev->left != cur)
                {
                    prev = prev->left;
                }
                if (prev->left == nullptr)
                {
                    // make thread
                    prev->left = cur;
                    cur = cur->right;
                }
                else
                {
                    // remove thread and visit
                    prev->left = nullptr;
                    count++;
                    if (count == k)
                        return cur->val;
                    cur = cur->left;
                }
            }
        }
        return -1; // k not valid
    }
};
