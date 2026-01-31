#include <bits/stdc++.h>
using namespace std;

// Using normal Recurssion...
int f1(int ind, int sum, vector<int> &num)
{
    if (sum == 0)
        return 1;
    if (ind == 0)
        return (num[0] == sum);

    int noteTake = f1(ind - 1, sum, num);
    int take = 0;
    if (num[ind] <= sum)
        take = f1(ind - 1, sum - num[ind], num);

    return take + noteTake;
}

int findWaysRec(vector<int> &num, int target)
{
    int n = num.size();
    return f1(n - 1, target, num);
}

// Using Memoization...
int f2(int ind, int sum, vector<int> &num, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (ind == 0)
        return (num[0] == sum);

    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    int noteTake = f2(ind - 1, sum, num, dp);
    int take = 0;
    if (num[ind] <= sum)
        take = f2(ind - 1, sum - num[ind], num, dp);

    return dp[ind][sum] = take + noteTake;
}

int findWaysMemo(vector<int> &num, int target)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return f2(n - 1, target, num, dp);
}

// Using Tabulation...

int findWaysTab(vector<int> &num, int target)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (num[0] <= target)
        dp[0][num[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= target; sum++)
        {
            int notTake = dp[ind - 1][sum];
            int take = 0;
            if (num[ind] <= sum)
                take = dp[ind - 1][sum - num[ind]];

            dp[ind][sum] = take + notTake;
        }
    }
    return dp[n - 1][target];
}

// Using Space Optimization...

int findWaysSpaceOpti(vector<int> &num, int target)
{
    int n = num.size();
    vector<int> prev(target + 1, 0), curr(target + 1, 0);
    prev[0] = curr[0] = 1;
    if (num[0] <= target)
        prev[num[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= target; sum++)
        {
            int notTake = prev[sum];
            int take = 0;
            if (num[ind] <= sum)
                take = prev[sum - num[ind]];

            curr[sum] = take + notTake;
        }
        prev = curr;
    }
    return prev[target];
}

// Example Implementation (Handles Negative Numbers)

int findWaysWithNegatives(vector<int> &num, int target)
{
    unordered_map<int, int> dp;
    dp[0] = 1; // one way to make sum 0

    for (int x : num)
    {
        unordered_map<int, int> newDp = dp; // notTake case

        for (auto &p : dp)
        {
            int sum = p.first;
            int cnt = p.second;

            newDp[sum + x] += cnt; // take case
        }
        dp = newDp;
    }

    return dp[target];
}
// DP 2D Subsequences
