#include <bits/stdc++.h>
using namespace std;

// Method : Adjacency Matrix
// Below method of rep. of graph takes O(N^2) space which is inefficient..

// int main(){
//     // n = no. of nodes, m = no. of edges
//     int n, m;
//     cin >> n >> m;
//     int adj[n + 1][m + 1];
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u][v] = 1;
//         adj[v][u] = 1;
//     }
//     return 0;
// }

// Method : Adjacency List
// Below method of rep. of graph takes O(2 * E) space which is much better..

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // if u --- v
        adj[u].push_back(v);
        adj[v].push_back(u);

        // if u ---> v
        // adj[u].push_back(v);
    }
    return 0;
}

/*
    till now all this was was un-weighted graphs
    storing only nodes like, {2, 3, 4} but,
    for weighted graphs we store pairs of (neighbour node, edge weight) like {(2, 5), (3, 2), (4, 1)}
*/