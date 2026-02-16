#include <bits/stdc++.h>
using namespace std;

// Using Recursion...

long fRecur(int ind, int buy, long *values, int n)
{
    if (ind == n)
        return 0;

    long profit = 0;

    if (buy)
    {
        profit = max(-values[ind] + fRecur(ind + 1, 0, values, n), 0 + fRecur(ind + 1, 1, values, n));
    }
    else
    {
        profit = max(values[ind] + fRecur(ind + 1, 1, values, n), 0 + fRecur(ind + 1, 0, values, n));
    }
    return profit;
}

long getMaximumProfit(long *values, int n)
{
    return fRecur(0, 1, values, n);
}

// Using Memoization...

long fMemo(int ind, int buy, long *values, int n, vector<vector<long>> &dp)
{
    if (ind == n)
        return 0;

    long profit = 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    if (buy)
    {
        profit = max(-values[ind] + fMemo(ind + 1, 0, values, n, dp), 0 + fMemo(ind + 1, 1, values, n, dp));
    }
    else
    {
        profit = max(values[ind] + fMemo(ind + 1, 1, values, n, dp), 0 + fMemo(ind + 1, 0, values, n, dp));
    }
    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return fMemo(0, 1, values, n, dp);
}

// Using Tabulation...

long getMaximumProfit_Tab(long *values, int n)
{
    vector<vector<long>> dp(n + 1, vector<long>(2, -1));
    dp[n][0] = 0;
    dp[n][1] = 0;

    long profit = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                profit = max(-values[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
            }
            else
            {
                profit = max(values[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

// Using Space Optimization...

long getMaximumProfit_SpaceOpti(long *values, int n)
{
    vector<long> ahead(2, 0), curr(2, 0);
    ahead[0] = 0;
    ahead[1] = 0;

    long profit = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                profit = max(-values[ind] + ahead[0], 0 + ahead[1]);
            }
            else
            {
                profit = max(values[ind] + ahead[1], 0 + ahead[0]);
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }
    return ahead[1];
}

// Using 4 variables...

long getMaximumProfit_SpaceOpti(long *values, int n)
{
    long aheadBuy = 0;    // dp[n][1]
    long aheadNotBuy = 0; // dp[n][0]

    for (int ind = n - 1; ind >= 0; ind--)
    {
        long currBuy = max(-values[ind] + aheadNotBuy, aheadBuy);

        long currNotBuy = max(values[ind] + aheadBuy, aheadNotBuy);

        aheadBuy = currBuy;
        aheadNotBuy = currNotBuy;
    }

    return aheadBuy;
}
