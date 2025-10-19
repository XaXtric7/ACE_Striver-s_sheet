#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int cntFresh = 0;

        // Step 1: Push all initially rotten oranges into the queue
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (grid[row][col] == 2)
                {
                    q.push({{row, col}, 0});
                    visited[row][col] = 2;
                }
                else
                {
                    visited[row][col] = 0;
                }
                if (grid[row][col] == 1)
                    cntFresh++;
            }
        }

        int time = 0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int count = 0;

        // Step 2: BFS traversal
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                // Check if adjacent cell is valid and fresh
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {

                    q.push({{nrow, ncol}, t + 1});
                    visited[nrow][ncol] = 2;
                    count++;
                }
            }
        }

        // Step 3: Check if all fresh oranges were rotten
        if (count != cntFresh)
            return -1;
        return time;
    }
};
