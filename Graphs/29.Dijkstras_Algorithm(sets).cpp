#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> dist(V, INF);

        st.insert({0, S});
        dist[S] = 0;

        while (!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            for (auto it : adj[node])
            {
                int edgeWeight = it[1];
                int adjNode = it[0];

                if (dis + edgeWeight < dist[adjNode])
                {
                    // erase if exist
                    if (dist[adjNode] != INF)
                    {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};