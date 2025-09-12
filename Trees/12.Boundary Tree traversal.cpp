/**
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

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void addLeftBoundary(Node *root, vector<int> &res)
    {
        Node *cur = root->left;
        while (cur)
        {
            if (!isLeaf(cur))
                res.push_back(cur->val);
            if (cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }

    void addRightBoundary(Node *root, vector<int> &res)
    {
        Node *cur = root->right;
        vector<int> tmp;
        while (cur)
        {
            if (!isLeaf(cur))
                tmp.push_back(cur->val);
            if (cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }
        for (int i = tmp.size() - 1; i >= 0; --i)
        {
            res.push_back(tmp[i]);
        }
    }

    void addLeaves(Node *root, vector<int> &res)
    {
        if (isLeaf(root))
        {
            res.push_back(root->val);
            return;
        }
        if (root->left)
            addLeaves(root->left, res);
        if (root->right)
            addLeaves(root->right, res);
    }

    bool isLeaf(Node *node)
    {
        return (node->left == NULL && node->right == NULL);
    }

    vector<int> printBoundary(Node *root)
    {
        vector<int> res;
        if (!root)
            return res;
        if (!isLeaf(root))
            res.push_back(root->val);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};
