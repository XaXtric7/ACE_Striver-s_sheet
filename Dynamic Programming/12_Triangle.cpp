#include <bits\stdc++.h>
using namespace std;

/*
Brute Force (Recursive):

int f(int i, int j, vector<vector<int>> &triangle, int n)
{
    if (i == n - 1)
        return triangle[n - 1][j];

    int d = triangle[i][j] + f(i + 1, j, triangle, n);
    int dg = triangle[i][j] + f(i + 1, j + 1, triangle, n);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    return f(0, 0, triangle, n);
}
*/

/*
Using DP and memoization:

int f(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp, int n)
{
    if (i == n - 1)
        return triangle[n - 1][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int d = triangle[i][j] + f(i + 1, j, triangle, dp, n);
    int dg = triangle[i][j] + f(i + 1, j + 1, triangle, dp, n);
    return dp[i][j] = min(d, dg);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(0, 0, triangle, dp, n);
}
*/

/*
Using Tabulation:

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int j = n - 1; j >= 0; j--)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int d = triangle[i][j] + dp[i + 1][j];
            int dg = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(d, dg);
        }
    }
    return dp[0][0];
}
*/

/*
Using Space Optimization:
*/

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<int> front(n, 0), curr(n, 0);
    for (int j = n - 1; j >= 0; j--)
    {
        front[j] = triangle[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int d = triangle[i][j] + front[j];
            int dg = triangle[i][j] + front[j + 1];
            curr[j] = min(d, dg);
        }
        front = curr;
    }
    return front[0];
}