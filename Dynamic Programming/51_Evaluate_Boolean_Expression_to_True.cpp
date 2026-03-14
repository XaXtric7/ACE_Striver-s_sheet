#include <bits/stdc++.h>
#define ll long long
using namespace std;

int mod = 1000000007;

// Using Recursion...

int fRecur(int i, int j, int isTrue, string &exp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
        {
            return exp[i] == 'T';
        }
        else
            return exp[i] == 'F';
    }
    ll ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        ll lT = fRecur(i, ind - 1, 1, exp);
        ll lF = fRecur(i, ind - 1, 0, exp);
        ll rT = fRecur(ind + 1, j, 1, exp);
        ll rF = fRecur(ind + 1, j, 0, exp);

        if (exp[ind] == '&')
        {
            if (isTrue)
                ways = (ways + (lT * rT) % mod) % mod;
            else
                ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|')
        {
            if (isTrue)
                ways = (ways + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
            else
                ways = (ways + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '^')
        {
            if (isTrue)
                ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
            else
                ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
        }
    }
    return ways;
}

int evaluateExp(string &exp)
{
    int n = exp.size();
    return fRecur(0, n - 1, 1, exp);
}

// Using Memoization...

int fMemo(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
        {
            return exp[i] == 'T';
        }
        else
            return exp[i] == 'F';
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    ll ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        ll lT = fMemo(i, ind - 1, 1, exp, dp);
        ll lF = fMemo(i, ind - 1, 0, exp, dp);
        ll rT = fMemo(ind + 1, j, 1, exp, dp);
        ll rF = fMemo(ind + 1, j, 0, exp, dp);

        if (exp[ind] == '&')
        {
            if (isTrue)
                ways = (ways + (lT * rT) % mod) % mod;
            else
                ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|')
        {
            if (isTrue)
                ways = (ways + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
            else
                ways = (ways + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '^')
        {
            if (isTrue)
                ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
            else
                ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}

int evaluateExp2(string &exp)
{
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return fMemo(0, n - 1, 1, exp, dp);
}