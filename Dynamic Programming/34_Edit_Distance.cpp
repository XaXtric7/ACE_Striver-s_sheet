#include <bits/stdc++.h>
using namespace std;

// Using Recursion...

int fRecur(int i, int j, string &s1, string &s2)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (s1[i] == s2[j])
        return fRecur(i - 1, j - 1, s1, s2);
    return 1 + min(fRecur(i, j - 1, s1, s2), min(fRecur(i - 1, j, s1, s2), fRecur(i - 1, j - 1, s1, s2)));
}

int editDistance1(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    return fRecur(n - 1, m - 1, str1, str2);
}

// Using Memoization...

int fMemo(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = fMemo(i - 1, j - 1, s1, s2, dp);
    return dp[i][j] = 1 + min(fMemo(i, j - 1, s1, s2, dp), min(fMemo(i - 1, j, s1, s2, dp), fMemo(i - 1, j - 1, s1, s2, dp)));
}

int editDistance2(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    return fMemo(n - 1, m - 1, str1, str2, dp);
}

// Using Tabulation...

int editDistance_Tab(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i; // delete all characters
    for (int j = 0; j <= m; j++)
        dp[0][j] = j; // insert all characters

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
        }
    }
    return dp[n][m];
}

// Using Space Optimization...

int editDistance_SpaceOpti(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        curr[0] = i; // delete all characters from s1
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = prev[j - 1];
            else
                curr[j] = 1 + min(curr[j - 1], min(prev[j], prev[j - 1]));
        }
        prev = curr;
    }
    return prev[m];
}