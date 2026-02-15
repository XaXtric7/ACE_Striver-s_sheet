#include <bits/stdc++.h>
using namespace std;

// Using Recursion...

bool fRecur(int i, int j, string &pattern, string &text)
{
    if (i < 0 && j < 0)
        return true; // both got exhausted
    if (i < 0 && j >= 0)
        return false; // s1 got exhausted
    if (j < 0 && i >= 0)
    { // s2 got exhausted
        for (int ii = 0; ii <= i; ii++)
        {
            if (pattern[ii] != '*')
                return false;
        }
        return true;
    }
    if (pattern[i] == text[j] || pattern[i] == '?')
    {
        return fRecur(i - 1, j - 1, pattern, text);
    }
    if (pattern[i] == '*')
    {
        return fRecur(i - 1, j, pattern, text) || fRecur(i, j - 1, pattern, text);
    }
    return false;
}

bool wildcardMatching1(string pattern, string text)
{
    int n = pattern.size();
    int m = text.size();
    return fRecur(n - 1, m - 1, pattern, text);
}

// Using Memoization...

bool fmemo(int i, int j, string &pattern, string &text, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return true; // both got exhausted
    if (i < 0 && j >= 0)
        return false; // s1 got exhausted
    if (j < 0 && i >= 0)
    { // s2 got exhausted
        for (int ii = 0; ii <= i; ii++)
        {
            if (pattern[ii] != '*')
                return false;
        }
        return true;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (pattern[i] == text[j] || pattern[i] == '?')
    {
        return dp[i][j] = fmemo(i - 1, j - 1, pattern, text, dp);
    }
    if (pattern[i] == '*')
    {
        return dp[i][j] = fmemo(i - 1, j, pattern, text, dp) || fmemo(i, j - 1, pattern, text, dp);
    }
    return dp[i][j] = false;
}

bool wildcardMatching2(string pattern, string text)
{
    int n = pattern.size();
    int m = text.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fmemo(n - 1, m - 1, pattern, text, dp);
}

// Using Memoization code as REF. for Tabulation...

// bool fmemo(int i, int j, string &pattern, string &text, vector<vector<int>> &dp)
// {
//     if (i == 0 && j == 0)
//         return true; // both got exhausted
//     if (i == 0 && j > 0)
//         return false; // s1 got exhausted
//     if (j == 0 && i > 0)
//     { // s2 got exhausted
//         for (int ii = 1; ii <= i; ii++)
//         {
//             if (pattern[ii - 1] != '*')
//                 return false;
//         }
//         return true;
//     }
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
//     {
//         return dp[i][j] = fmemo(i - 1, j - 1, pattern, text, dp);
//     }
//     if (pattern[i - 1] == '*')
//     {
//         return dp[i][j] = fmemo(i - 1, j, pattern, text, dp) || fmemo(i, j - 1, pattern, text, dp);
//     }
//     return dp[i][j] = false;
// }

// Using Tabulation...

bool wildcardMatching_Tab(string pattern, string text)
{
    int n = pattern.size();
    int m = text.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (pattern[i - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}

// Using Space Optimization...

bool wildcardMatching_SpaceOpti(string pattern, string text)
{
    int n = pattern.size();
    int m = text.size();
    vector<bool> prev(m + 1, false), curr(m + 1, false);
    prev[0] = true;
    for (int j = 1; j <= m; j++)
    {
        prev[j] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        curr[0] = flag;
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
            {
                curr[j] = prev[j - 1];
            }
            else if (pattern[i - 1] == '*')
            {
                curr[j] = prev[j] || curr[j - 1];
            }
            else
                curr[j] = false;
        }
        prev = curr;
    }
    return prev[m];
}