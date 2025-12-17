#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

class Solution
{
public:
    int minimumEffort(vector<vector<int>> &heights)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int n = heights.size();    // no. of rows
        int m = heights[0].size(); // no. of columns

        vector<vector<int>> dist(n, vector<int>(m, INF));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n - 1 && col == m - 1)
                return diff;

            for (int i = 0; i < 4; i++)
            {
                int newr = row + dr[i];
                int newc = col + dc[i];
                if (newr >= 0 && newr < n && newc >= 0 && newc < m)
                {
                    int newEfforts = max(abs(heights[row][col] - heights[newr][newc]), diff);
                    if (newEfforts < dist[newr][newc])
                    {
                        dist[newr][newc] = newEfforts;
                        pq.push({newEfforts, {newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};