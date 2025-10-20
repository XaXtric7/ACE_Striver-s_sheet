#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool detectCycle(int src, vector<int> adj[], vector<int> &visited)
    {
        visited[src] = 1;
        queue<pair<int, int>> q; // {node, parent}
        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjacentNode : adj[node])
            {
                if (!visited[adjacentNode])
                {
                    visited[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                // If visited and not coming from the same parent → cycle
                else if (adjacentNode != parent)
                {
                    return true;
                }
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
                if (detectCycle(i, adj, visited))
                    return true;
            }
        }
        return false;
    }
};
