#include <bits/stdc++.h>
using namespace std;

// Using Recursion...

int fRecur(int i, int j, vector<int> &cuts)
{
    if (i > j)
        return 0;

    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + fRecur(i, ind - 1, cuts) + fRecur(ind + 1, j, cuts);
        mini = min(mini, cost);
    }
    return mini;
}

int cost(int n, int c, vector<int> &cuts)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    return fRecur(1, c, cuts);
}

// Using Memoization...

int fMemo(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + fMemo(i, ind - 1, cuts, dp) + fMemo(ind + 1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

int cost2(int n, int c, vector<int> &cuts)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return fMemo(1, c, cuts, dp);
}

// Using Tabulation...

int cost_Tab(int n, int c, vector<int> &cuts)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--)
    {
        for (int j = i; j <= c; j++)
        {
            int mini = INT_MAX;

            for (int ind = i; ind <= j; ind++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];

                mini = min(mini, cost);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][c];
}