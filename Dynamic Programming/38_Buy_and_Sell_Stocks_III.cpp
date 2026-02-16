#include <bits/stdc++.h>
using namespace std;

// Using Recursion...

int fRecur(int ind, int buy, int cap, vector<int> &prices, int n)
{
    if (ind == n || cap == 0)
        return 0;
    if (buy == 1)
    {
        return max(-prices[ind] + fRecur(ind + 1, 0, cap, prices, n), 0 + fRecur(ind + 1, 1, cap, prices, n));
    }
    else
    {
        return max(prices[ind] + fRecur(ind + 1, 1, cap - 1, prices, n), 0 + fRecur(ind + 1, 0, cap, prices, n));
    }
}

int maxProfit1(vector<int> &prices, int n)
{
    return fRecur(0, 1, 2, prices, n);
}

// Using Memoization...

int fMemo(int ind, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)
{
    if (ind == n || cap == 0) // Base cases
        return 0;
    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];
    if (buy == 1)
    {
        return dp[ind][buy][cap] = max(-prices[ind] + fMemo(ind + 1, 0, cap, prices, n, dp), 0 + fMemo(ind + 1, 1, cap, prices, n, dp));
    }
    else
    {
        return dp[ind][buy][cap] = max(prices[ind] + fMemo(ind + 1, 1, cap - 1, prices, n, dp), 0 + fMemo(ind + 1, 0, cap, prices, n, dp));
    }
}

int maxProfit2(vector<int> &prices, int n)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return fMemo(0, 1, 2, prices, n, dp);
}

// Using Tabulation...

int maxProfit_Tab(vector<int> &prices, int n)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            { // cap[0] = 0; ignore
                if (buy == 1)
                {
                    dp[ind][buy][cap] = max(-prices[ind] + dp[ind + 1][0][cap], 0 + dp[ind + 1][1][cap]);
                }
                else
                {
                    dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1], 0 + dp[ind + 1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}

// Using Space Optimization...

int maxProfit_SpaceOpti(vector<int> &prices, int n)
{
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            { // cap[0] = 0; ignore
                if (buy == 1)
                {
                    curr[buy][cap] = max(-prices[ind] + after[0][cap], 0 + after[1][cap]);
                }
                else
                {
                    curr[buy][cap] = max(prices[ind] + after[1][cap - 1], 0 + after[0][cap]);
                }
            }
        }
        after = curr;
    }
    return after[1][2];
}