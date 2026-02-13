#include <bits/stdc++.h>
using namespace std;

// Using Recursion...

int fRecur(int i, int j, string &s, string &t)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (s[i] == t[j])
        return 1 + fRecur(i - 1, j - 1, s, t);
    return max(fRecur(i - 1, j, s, t), fRecur(i, j - 1, s, t));
}

int lcsRecur(string s, string t)
{
    int n = s.size();
    int m = t.size();

    return fRecur(n - 1, m - 1, s, t);
}

// Using Memoization...

int fMemo(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
        return dp[i][j] = 1 + fMemo(i - 1, j - 1, s, t, dp);
    return dp[i][j] = max(fMemo(i - 1, j, s, t, dp), fMemo(i, j - 1, s, t, dp));
}

int lcsMemo(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    return fMemo(n - 1, m - 1, s, t, dp);
}

// Using Tabulation...

int lcsTab(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

// Using Space Optimization...

int lcsSpaceOpti(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
}