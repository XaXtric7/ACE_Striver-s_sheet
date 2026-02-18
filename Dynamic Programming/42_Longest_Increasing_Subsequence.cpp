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
int longestIncreasingSubsequence_Tab(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int len = 0 + dp[ind + 1][prev_ind + 1];
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
            {
                len = max(len, 1 + dp[ind + 1][ind + 1]);
            }
            dp[ind][prev_ind + 1] = len;
        }
    }
    return dp[0][-1 + 1];
}

// Using Space Optimization...

int longestIncreasingSubsequence_SpaceOpti(int arr[], int n)
{
    vector<int> next(n + 1, 0), cur(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int len = 0 + next[prev_ind + 1];
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
            {
                len = max(len, 1 + next[ind + 1]);
            }
            cur[prev_ind + 1] = len;
        }
        next = cur;
    }
    return next[-1 + 1];
}

// Using Algorithm...

int longestIncreasingSubsequence1(int arr[], int n)
{
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

// Using Optimal LIS (Binary Search – O[n log n])

int longestIncreasingSubsequence2(int arr[], int n)
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

// LIS...
int longestStrChain3(vector<string> &arr)
{
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for(int i = 0; i<n; i++) {
        hash[i] = i;
        for(int prev = 0; prev < i; prev++) {
            if(arr[prev] < arr[i] &&
               1 + dp[prev] > dp[i]) {
                
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi) {
            maxi = dp[i];
            lastIndex = i;
        }
    }
}