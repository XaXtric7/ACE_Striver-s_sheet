#include <bits\stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = f(i - 1, j, dp);
    int left = f(i, j - 1, dp);
    return dp[i][j] = up + left;
}
int UniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, dp);
}
/*
int UniquePaths(int m, int n)
{
    vector<int> dp(n, 1);

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}
*/