#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];

    int k = totSum;

    // vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // // Base case: sum 0 is always possible
    // for (int i = 0; i < n; i++)
    //     dp[i][0] = true;

    // if (arr[0] <= k)
    //     dp[0][arr[0]] = true;

    // for (int ind = 1; ind < n; ind++)
    // {
    //     for (int target = 1; target <= k; target++)
    //     {
    //         bool notTake = dp[ind - 1][target];
    //         bool take = false;
    //         if (arr[ind] <= target)
    //             take = dp[ind - 1][target - arr[ind]];

    //         dp[ind][target] = take || notTake;
    //     }
    // }

    // Space optimized
    vector<bool> prev(k + 1, 0), curr(k + 1, 0);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (arr[ind] <= target)
                take = prev[target - arr[ind]];
            curr[target] = take || notTake;
        }
        prev = curr;
    }

    int mini = 1e9;
    for (int s1 = 0; s1 <= totSum / 2; s1++)
    {
        if (prev[s1])
        {
            int s2 = totSum - s1;
            mini = min(mini, abs(s2 - s1));
        }
    }
    return mini;
}
