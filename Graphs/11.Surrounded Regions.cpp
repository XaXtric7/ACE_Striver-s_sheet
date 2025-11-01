#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int delrow[], int delcol[])
    {
        vis[row][col] = 1;
        int n = mat.size();    // no. of rows
        int m = mat[0].size(); // no. of column

        // check the top, right, bottom, left
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0)); // visited tracker

        // traverse the first and the last row
        for (int j = 0; j < m; j++)
        {
            // first row
            if (vis[0][j] == 0 && mat[0][j] == 'O')
            {
                // if not visited and present in 'mat' as '0'
                dfs(0, j, vis, mat, delrow, delcol);
            }
            // last row
            if (vis[n - 1][j] == 0 && mat[n - 1][j] == 'O')
            {
                // if not visited and present in 'mat' as '0'
                dfs(n - 1, j, vis, mat, delrow, delcol);
            }
        }

        // traverse the first column and the last column
        for (int i = 0; i < n; i++)
        {
            // first column
            if (vis[i][0] == 0 && mat[i][0] == 'O')
            {
                // if not visited and present in 'mat' as '0'
                dfs(i, 0, vis, mat, delrow, delcol);
            }
            // last column
            if (vis[i][m - 1] == 0 && mat[i][m - 1] == 'O')
            {
                // if not visited and present in 'mat' as '0'
                dfs(i, m - 1, vis, mat, delrow, delcol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 0 && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};
