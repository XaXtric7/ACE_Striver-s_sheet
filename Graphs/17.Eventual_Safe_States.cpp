#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, vector<int> &check)
    {
        vis[node] = 1;
        pathVis[node] = 1;

        // Explore all adjacent nodes
        for (int next : adj[node])
        {

            // If not visited, DFS on it
            if (!vis[next])
            {
                if (dfsCheck(next, adj, vis, pathVis, check))
                    return true; // cycle found
            }
            // If visited AND currently on the path → cycle
            else if (pathVis[next])
            {
                return true;
            }
        }
        // No cycle found → mark safe
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<vector<int>> &adj)
    {

        vector<int> vis(V, 0), pathVis(V, 0), check(V, 0);

        // Call DFS for each unvisited node
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsCheck(i, adj, vis, pathVis, check);
            }
        }

        // Collect safe nodes
        vector<int> safeNodes;
        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
                safeNodes.push_back(i);
        }

        return safeNodes;
    }
};
