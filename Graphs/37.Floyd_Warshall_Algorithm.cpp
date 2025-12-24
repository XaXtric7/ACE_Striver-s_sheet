#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // Preprocessing
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                    matrix[i][j] = INF;
                if (i == j)
                    matrix[i][j] = 0;
            }
        }

        // Floyd–Warshall
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][k] != INF && matrix[k][j] != INF)
                    {
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }

        // Postprocessing
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == INF)
                    matrix[i][j] = -1;
            }
        }
    }
};
