#include <bits/stdc++.h>
using namespace std;

// Using Recursion...

int fRecur(int ind, int k, int n, vector<int> &arr)
{
    if (ind == n)
        return 0;
    int maxAns = INT_MIN;
    int len = 0, maxi = INT_MIN;
    for (int j = ind; j < min(n, ind + k); j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        int sum = 0;
        sum = len * maxi + fRecur(j + 1, k, n, arr);
        maxAns = max(maxAns, sum);
    }
    return maxAns;
}

int maximumSubarray(vector<int> &arr, int k)
{
    int n = arr.size();
    return fRecur(0, k, n, arr);
}

// Using Memoization...

int fMemo(int ind, int k, int n, vector<int> &arr, vector<int> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int maxAns = INT_MIN;
    int len = 0, maxi = INT_MIN;
    for (int j = ind; j < min(n, ind + k); j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        int sum = 0;
        sum = len * maxi + fMemo(j + 1, k, n, arr, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[ind] = maxAns;
}

int maximumSubarray2(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    return fMemo(0, k, n, arr, dp);
}

// Using Tabulation...

int maximumSubarray_Tab(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        int maxAns = INT_MIN;
        int len = 0, maxi = INT_MIN;
        for (int j = ind; j < min(n, ind + k); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = 0;
            sum = len * maxi + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        dp[ind] = maxAns;
    }
    return dp[0];
}