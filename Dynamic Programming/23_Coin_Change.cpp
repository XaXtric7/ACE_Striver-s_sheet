#include <bits/stdc++.h>
using namespace std;

// Using Recursion...

long fRecur(int ind, int T, int *a)
{
    if (ind == 0)
    {
        return (T % a[0] == 0);
    }
    long notTake = fRecur(ind - 1, T, a);
    long take = 0;
    if (a[ind] <= T)
        take = fRecur(ind, T - a[ind], a);
    return take + notTake;
}

long countWaysToMakeChange(int *denomination, int n, int value)
{
    return fRecur(n - 1, value, denomination);
}

// Using Memoization...

long fMemo(int ind, int T, int *a, vector<vector<long>> &dp)
{
    if (ind == 0)
    {
        return (T % a[0] == 0);
    }
    if (dp[ind][T] != -1)
        return dp[ind][T];
    long notTake = fMemo(ind - 1, T, a, dp);
    long take = 0;
    if (a[ind] <= T)
        take = fMemo(ind, T - a[ind], a, dp);
    return dp[ind][T] = take + notTake;
}

long countWaysToMakeChange2(int *denomination, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return fMemo(n - 1, value, denomination, dp);
}

// Using Tabulation...

long countWaysToMakeChange2(int *denomination, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    for (int T = 0; T <= value; T++)
    {
        dp[0][T] = (T % denomination[0] == 0);
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= value; T++)
        {
            long notTake = dp[ind - 1][T];
            long take = 0;
            if (denomination[ind] <= T)
                take = dp[ind][T - denomination[ind]];
            dp[ind][T] = take + notTake;
        }
    }
    return dp[n - 1][value];
}

// Using Space Optimization...

long countWaysToMakeChange3(int *denomination, int n, int value)
{
    vector<long> prev(value + 1, 0), curr(value + 1, 0);
    for (int T = 0; T <= value; T++)
    {
        prev[T] = (T % denomination[0] == 0);
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= value; T++)
        {
            long notTake = prev[T];
            long take = 0;
            if (denomination[ind] <= T)
                take = curr[T - denomination[ind]];
            curr[T] = take + notTake;
        }
        prev = curr;
    }
    return prev[value];
}