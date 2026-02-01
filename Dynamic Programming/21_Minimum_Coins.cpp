#include <bits/stdc++.h>
using namespace std;

// Using Recursion...

int fRecur(int ind, int T, vector<int> &nums)
{
    if (ind == 0)
    {
        if (T % nums[0] == 0)
            return T / nums[0];
        else
            return 1e9;
    }
    int notTake = 0 + fRecur(ind - 1, T, nums);
    int take = INT_MAX;
    if (nums[ind] <= T)
    {
        take = 1 + fRecur(ind, T - nums[ind], nums);
    }
    return min(take, notTake);
}

int minimumElements1(vector<int> &nums, int target)
{
    int n = nums.size();
    int ans = fRecur(n - 1, target, nums);
    if (ans >= 1e9)
        return -1;
    return ans;
}

// Using Memoization...

int fMemo(int ind, int T, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (T % nums[0] == 0)
            return T / nums[0];
        else
            return 1e9;
    }
    if (dp[ind][T] != -1)
        return dp[ind][T];
    int notTake = 0 + fMemo(ind - 1, T, nums, dp);
    int take = INT_MAX;
    if (nums[ind] <= T)
    {
        take = 1 + fMemo(ind, T - nums[ind], nums, dp);
    }
    return dp[ind][T] = min(take, notTake);
}

int minimumElements2(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    int ans = fMemo(n - 1, target, nums, dp);
    if (ans >= 1e9)
        return -1;
    return ans;
}

// Using Tabulation...

int minimumElements_Tab(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for (int T = 0; T <= target; T++)
    {
        if (T % nums[0] == 0)
            dp[0][T] = T / nums[0];
        else
            dp[0][T] = 1e9;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= target; T++)
        {
            int notTake = 0 + dp[ind - 1][T];
            int take = INT_MAX;
            if (nums[ind] <= T)
            {
                take = 1 + dp[ind][T - nums[ind]];
            }
            dp[ind][T] = min(take, notTake);
        }
    }
    int ans = dp[n - 1][target];
    if (ans >= 1e9)
        return -1;
    return ans;
}

// Using Space Optimization...

int minimumElements_SpaceOpti(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> prev(target + 1, 0), curr(target + 1, 0);
    for (int T = 0; T <= target; T++)
    {
        if (T % nums[0] == 0)
            prev[T] = T / nums[0];
        else
            prev[T] = 1e9;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= target; T++)
        {
            int notTake = 0 + prev[T];
            int take = 1e9;
            if (nums[ind] <= T)
            {
                take = 1 + curr[T - nums[ind]];
            }
            curr[T] = min(take, notTake);
        }
        prev = curr;
    }
    int ans = prev[target];
    if (ans >= 1e9)
        return -1;
    return ans;
}