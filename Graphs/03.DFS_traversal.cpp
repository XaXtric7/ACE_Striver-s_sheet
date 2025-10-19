#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adj[], int visited[], vector<int> &ls)
    {
        visited[node] = 1;
        ls.push_back(node);
        // traverse all its neighbours
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfs(it, adj, visited, ls);
            }
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        int start = 0;
        vector<int> ls;
        dfs(start, adj, visited, ls);
        return ls;
    }
};