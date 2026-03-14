#include <bits/stdc++.h>
using namespace std;

// Using Recursion...

int fRecur(int i, int j, vector<int> &arr)
{
    if (i > j)
        return 0;

    int maxi = INT_MIN;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = arr[i - 1] * arr[ind] * arr[j + 1] + fRecur(i, ind - 1, arr) + fRecur(ind + 1, j, arr);
        maxi = max(maxi, cost);
    }
    return maxi;
}

int maxCoins(vector<int> &arr)
{
    int n = arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    return fRecur(1, n, arr);
}

// Using Memoization...

int fMemo(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int maxi = INT_MIN;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = arr[i - 1] * arr[ind] * arr[j + 1] + fMemo(i, ind - 1, arr, dp) + fMemo(ind + 1, j, arr, dp);
        maxi = max(maxi, cost);
    }
    return dp[i][j] = maxi;
}

int maxCoins2(vector<int> &arr)
{
    int n = arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return fMemo(1, n, arr, dp);
}

// Using Tabulation...

int maxCoin_Tabulation(vector<int> &arr)
{
    int n = arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
                continue;
            int maxi = INT_MIN;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = arr[i - 1] * arr[ind] * arr[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}