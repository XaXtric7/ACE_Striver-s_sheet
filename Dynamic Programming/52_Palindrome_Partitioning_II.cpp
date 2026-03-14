#include <bits/stdc++.h>
using namespace std;
// Front Partition

// Using Recursion...

bool isPalindrome(int i, int j, string &str)
{
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int fRecur(int i, int n, string &str)
{
    if (i == n)
        return 0;

    int minCost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, str))
        {
            int cost = 1 + fRecur(j + 1, n, str);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

int palindromePartition(string &str)
{
    int n = str.size();
    return fRecur(0, n, str) - 1;
}

// Using Memoization...

int fMemo(int i, int n, string &str, vector<int> &dp)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int minCost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, str))
        {
            int cost = 1 + fMemo(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}

int palindromePartition(string &str)
{
    int n = str.size();
    vector<int> dp(n, -1);
    return fMemo(0, n, str, dp) - 1;
}

// Using Tabulation...

int palindromePartition_Tab(string &str)
{
    int n = str.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0; // base case i == n return 0
    for (int i = n - 1; i >= 0; i--)
    {
        int minCost = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, str))
            {
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0] - 1;
}