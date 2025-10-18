#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;                   // number of vertices
    vector<vector<int>> adj; // adjacency list

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); // remove this line for directed graph
    }

    // bfs traversal from the source node
    void bfs(int start)
    {
        vector<bool> visited(V, false); // of size V and filled with 'false' at all indices
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << start;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};