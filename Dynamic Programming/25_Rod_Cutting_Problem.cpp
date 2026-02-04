#include <bits/stdc++.h>
using namespace std;

// Using Recursion...

int fRecur(int ind, int N, vector<int> &price)
{
    if (ind == 0)
        return N * price[0];

    int notTake = 0 + fRecur(ind - 1, N, price);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if (rodLength <= N)
    {
        take = price[ind] + fRecur(ind, N - rodLength, price);
    }
    return max(take, notTake);
}
int cutrod(vector<int> &price, int n)
{
    return fRecur(n - 1, n, price);
}

// Using Memoization...

int fMemo(int ind, int N, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
        return N * price[0];
    if (dp[ind][N] != -1)
        return dp[ind][N];
    int notTake = 0 + fMemo(ind - 1, N, price, dp);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if (rodLength <= N)
    {
        take = price[ind] + fMemo(ind, N - rodLength, price, dp);
    }
    return dp[ind][N] = max(take, notTake);
}
int cutrod2(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return fMemo(n - 1, n, price, dp);
}

// Using Tabulation...

int cutrod_Tab(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int N = 0; N <= n; N++)
    {
        dp[0][N] = N * price[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 + dp[ind - 1][N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if (rodLength <= N)
            {
                take = price[ind] + dp[ind][N - rodLength];
            }
            dp[ind][N] = max(take, notTake);
        }
    }
    return dp[n - 1][n];
}

// Using Space Optimization...

int cutrod_Tab(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int N = 0; N <= n; N++)
    {
        prev[N] = N * price[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 + prev[N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if (rodLength <= N)
            {
                take = price[ind] + curr[N - rodLength];
            }
            curr[N] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[n];
}

// Using Space Optimization(1 - D)...

int cutrod_Tab(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0);
    for (int N = 0; N <= n; N++)
    {
        prev[N] = N * price[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 + prev[N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if (rodLength <= N)
            {
                take = price[ind] + prev[N - rodLength];
            }
            prev[N] = max(take, notTake);
        }
    }
    return prev[n];
}