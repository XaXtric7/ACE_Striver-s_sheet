#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<vector<int>> &adjLs, int visited[])
    {
        visited[node] = 1;
        for (auto it : adjLs[node])
        {
            if (!visited[it])
            {
                dfs(it, adjLs, visited);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {

        // changing the adjacency matrix to the adjacency list
        vector<vector<int>> adjLs(V);

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        int visited[V] = {0};
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adjLs, visited);
            }
        }
        return count;
    }
};