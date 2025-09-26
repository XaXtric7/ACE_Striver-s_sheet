/*
 * Definition for a binary tree node.
 * struct BinaryTreeNode {
 *     int val;
 *     BinaryTreeNode *left;
 *     BinaryTreeNode *right;
 *     BinaryTreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findMaxDistance(map<BinaryTreeNode *, BinaryTreeNode *> &mpp,
                    BinaryTreeNode *target)
{
    queue<BinaryTreeNode *> q;
    q.push(target);
    map<BinaryTreeNode *, int> vis;
    vis[target] = 1;
    int maxi = 0;

    while (!q.empty())
    {
        int sz = q.size();
        int fl = 0;
        for (int i = 0; i < sz; i++)
        {
            auto node = q.front();
            q.pop();

            if (node->left && !vis[node->left])
            {
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if (node->right && !vis[node->right])
            {
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            if (mpp[node] && !vis[mpp[node]])
            {
                fl = 1;
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }
        if (fl)
            maxi++;
    }
    return maxi;
}

BinaryTreeNode *bfsToMapParents(BinaryTreeNode *root,
                                map<BinaryTreeNode *, BinaryTreeNode *> &mpp,
                                int start)
{
    queue<BinaryTreeNode *> q;
    q.push(root);
    BinaryTreeNode *res = nullptr;

    while (!q.empty())
    {
        auto node = q.front();
        if (node->val == start)
            res = node;
        q.pop();

        if (node->left)
        {
            mpp[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

int timeToBurnTree(BinaryTreeNode *root, int start)
{
    map<BinaryTreeNode *, BinaryTreeNode *> mpp;
    BinaryTreeNode *target = bfsToMapParents(root, mpp, start);
    int maxi = findMaxDistance(mpp, target);
    return maxi;
}
