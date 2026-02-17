#include <bits/stdc++.h>
using namespace std;

// Using Recursion...

int fRecur(int ind, int prev_ind, int arr[], int n)
{
    if (ind == n)
        return 0;

    int len = 0 + fRecur(ind + 1, prev_ind, arr, n); // not take
    if (prev_ind == -1 || arr[ind] >= arr[prev_ind])
    { // take
        len = max(len, 1 + fRecur(ind + 1, ind, arr, n));
    }
    return len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    return fRecur(0, -1, arr, n);
}

// Using Memoization...

int fMemo(int ind, int prev_ind, int arr[], int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];
    int len = 0 + fMemo(ind + 1, prev_ind, arr, n, dp); // not take
    if (prev_ind == -1 || arr[ind] >= arr[prev_ind])
    { // take
        len = max(len, 1 + fMemo(ind + 1, ind, arr, n, dp));
    }
    return dp[ind][prev_ind + 1] = len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return fMemo(0, -1, arr, n, dp);
}

// Using Tabulation...O[n^2]
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);

    return ans;
}

// Using Optimal LIS (Binary Search – O[n log n])

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;

    temp.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }

    return temp.size();
}
