#include <bits/stdc++.h>
using namespace std;

// Using Recursion...

int fRecur(int ind, int W, vector<int> &val, vector<int> &wt)
{
    if (ind == 0)
    {
        return ((int)(W / wt[0])) * val[0];
    }
    int notTake = 0 + fRecur(ind - 1, W, val, wt);
    int take = 0;
    if (wt[ind] <= W)
        take = val[ind] + fRecur(ind, W - wt[ind], val, wt);
    return max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
    return fRecur(n - 1, w, val, wt);
}

// Using Memoization...

int fMemo(int ind, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return ((int)(W / wt[0])) * val[0];
    }
    if (dp[ind][W] != -1)
        return dp[ind][W];
    int notTake = 0 + fMemo(ind - 1, W, val, wt, dp);
    int take = 0;
    if (wt[ind] <= W)
        take = val[ind] + fMemo(ind, W - wt[ind], val, wt, dp);
    return dp[ind][W] = max(take, notTake);
}

int unboundedKnapsack2(int n, int w, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return fMemo(n - 1, w, val, wt, dp);
}

// Using Tabulation...

int unboundedKnapsack_Tab(int n, int w, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int W = 0; W <= w; W++)
    {
        dp[0][W] = ((int)(W / wt[0])) * val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= w; W++)
        {
            int notTake = 0 + dp[ind - 1][W];
            int take = 0;
            if (wt[ind] <= W)
                take = val[ind] + dp[ind][W - wt[ind]];
            dp[ind][W] = max(take, notTake);
        }
    }
    return dp[n - 1][w];
}

// Using Space Optimization...

int unboundedKnapsack_SpaceOpti(int n, int w, vector<int> &val, vector<int> &wt)
{
    vector<int> prev(w + 1, 0), curr(w + 1, 0);
    for (int W = 0; W <= w; W++)
    {
        prev[W] = ((int)(W / wt[0])) * val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= w; W++)
        {
            int notTake = 0 + prev[W];
            int take = 0;
            if (wt[ind] <= W)
                take = val[ind] + curr[W - wt[ind]];
            curr[W] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[w];
}

// Using Space Optimization(1 - D)...

int unboundedKnapsack_SpaceOpti2(int n, int w, vector<int> &val, vector<int> &wt)
{
    vector<int> prev(w + 1, 0);
    for (int W = 0; W <= w; W++)
    {
        prev[W] = ((int)(W / wt[0])) * val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= w; W++)
        {
            int notTake = 0 + prev[W];
            int take = 0;
            if (wt[ind] <= W)
                take = val[ind] + prev[W - wt[ind]];
            prev[W] = max(take, notTake);
        }
    }
    return prev[w];
}