#include <bits/stdc++.h>
using namespace std;

// Using Recursion...

int fRecur(int ind, int prev, vector<int> &arr, int n)
{
    if (ind == n)
        return 0;

    int notTake = fRecur(ind + 1, prev, arr, n);

    int take = 0;
    if (prev == -1 || arr[ind] % arr[prev] == 0)
        take = 1 + fRecur(ind + 1, ind, arr, n);

    return max(take, notTake);
}

int largestDivisibleSubset1(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    return fRecur(0, -1, arr, arr.size());
}

// Using Memoization...

int fMemo(int ind, int prev, vector<int> &arr, int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];

    int notTake = fMemo(ind + 1, prev, arr, n, dp);

    int take = 0;
    if (prev == -1 || arr[ind] % arr[prev] == 0)
        take = 1 + fMemo(ind + 1, ind, arr, n, dp);

    return dp[ind][prev + 1] = max(take, notTake);
}

int largestDivisibleSubset2(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return fMemo(0, -1, arr, n, dp);
}

// Using Tabulation...

int largestDivisibleSubset_Tab(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    vector<int> dp(n, 1);
    int maxi = 1;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] % arr[prev] == 0)
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }

    return maxi;
}