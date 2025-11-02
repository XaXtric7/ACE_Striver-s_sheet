#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, int color[], vector<int> adj[])
    {
        for (auto it : adj[node])
        {
            // if the adjacent node is not yet colored
            if (color[it] == -1)
            {
                // give alternate color
                color[it] = !color[node];
                // recursive DFS call
                if (!dfs(it, color, adj))
                    return false;
            }
            // if adjacent node already has same color → not bipartite
            else if (color[it] == color[node])
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        int color[V];
        for (int i = 0; i < V; i++)
            color[i] = -1; // uncolored

        // handle disconnected components
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                color[i] = 0; // start coloring
                if (!dfs(i, color, adj))
                    return false;
            }
        }
        return true;
    }
};
