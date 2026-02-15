#include <bits/stdc++.h>
using namespace std;

// Using Recursion...
class Solution_Recur
{
private:
    int fRecur(int i, int j, string &s, string &t)
    {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;
        if (s[i] == t[j])
        {
            return fRecur(i - 1, j - 1, s, t) + fRecur(i - 1, j, s, t);
        }
        return fRecur(i - 1, j, s, t);
    }

public:
    int numDistinct1(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        return fRecur(n - 1, m - 1, s, t);
    }
};

// Using Memoization...
class Solution_Memo
{
private:
    long long fMemo(int i, int j, string &s, string &t, vector<vector<long long>> &dp)
    {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
        {
            return dp[i][j] = fMemo(i - 1, j - 1, s, t, dp) + fMemo(i - 1, j, s, t, dp);
        }
        return dp[i][j] = fMemo(i - 1, j, s, t, dp);
    }

public:
    int numDistinct2(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        return fMemo(n - 1, m - 1, s, t, dp);
    }
};

// Using Tabulation...
class Solution_Tab
{
public:
    int numDistinct3(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int j = 1; j <= m; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};

// Using Space Optimization...
class Solution_SpaceOpti
{
public:
    long long numDistinct4(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<long long> prev(m + 1, 0), curr(m + 1, 0);

        prev[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            curr[0] = 1;
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    curr[j] = prev[j - 1] + prev[j];
                }
                else
                {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

// Using Space Optimization(1-D)...
class Solution_SpaceOpti2
{
public:
    long long numDistinct5(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<long long> prev(m + 1, 0);
        prev[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])
                    prev[j] += prev[j - 1];
            }
        }
        return prev[m];
    }
};