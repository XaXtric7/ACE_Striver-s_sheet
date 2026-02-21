#include <bits/stdc++.h>
using namespace std;

// Mine...

int longestIncreasingSubsequence1(vector<int> &arr, int n)
{
    vector<int> dp1(n, 1);

    // LIS from left
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i])
            {
                dp1[i] = max(dp1[i], 1 + dp1[prev]);
            }
        }
    }

    vector<int> dp2(n, 1);

    // LIS from right (i.e., Longest Decreasing Subsequence)
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = n - 1; prev > i; prev--)
        {
            if (arr[prev] < arr[i])
            {
                dp2[i] = max(dp2[i], 1 + dp2[prev]);
            }
        }
    }

    int maxii = 0;

    // Find maximum bitonic length
    for (int i = 0; i < n; i++)
    {
        maxii = max(maxii, dp1[i] + dp2[i] - 1);
    }

    int count = 0;

    // Count how many indices give maximum bitonic length
    for (int i = 0; i < n; i++)
    {
        if (dp1[i] + dp2[i] - 1 == maxii)
            count++;
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence1(arr, n);

    return 0;
}

// Striver's...

int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();

    vector<int> dp(n, 1), cnt(n, 1);

    int maxi = 1;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                cnt[i] = cnt[prev]; // inherit count
            }
            else if (arr[prev] < arr[i] && 1 + dp[prev] == dp[i])
            {
                cnt[i] += cnt[prev]; // increase count
            }
        }

        maxi = max(maxi, dp[i]);
    }

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
            total += cnt[i];
    }

    return total;
}