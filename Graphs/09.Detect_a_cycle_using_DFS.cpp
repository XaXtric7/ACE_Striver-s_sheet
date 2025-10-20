#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, int parent, vector<int> &visited, vector<int> adj[])
    {
        visited[node] = 1;

        for (auto adjacentNode : adj[node])
        {
            if (!visited[adjacentNode])
            {
                if (dfs(adjacentNode, node, visited, adj))
                    return true;
            }
            else if (adjacentNode != parent)
            {
                // A visited node not equal to parent -> cycle detected
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, -1, visited, adj))
                    return true;
            }
        }
        return false;
    }
};
