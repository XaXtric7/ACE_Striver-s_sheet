#include <bits/stdc++.h>
using namespace std;

// Using Recursion...

class Solution_recur
{
private:
    int fRecur(int ind, int buy, vector<int> &prices)
    {
        if (ind >= prices.size())
            return 0;

        if (buy == 1)
        {
            return max(-prices[ind] + fRecur(ind + 1, 0, prices), 0 + fRecur(ind + 1, 1, prices));
        }
        else
        {
            return max(prices[ind] + fRecur(ind + 2, 1, prices), 0 + fRecur(ind + 1, 0, prices));
        }
    }

public:
    int maxProfit1(vector<int> &prices)
    {
        return fRecur(0, 1, prices);
    }
};

// Using Memoization...

class Solution_memo
{
private:
    int fMemo(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (ind >= prices.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy == 1)
        {
            return dp[ind][buy] = max(-prices[ind] + fMemo(ind + 1, 0, prices, dp), 0 + fMemo(ind + 1, 1, prices, dp));
        }
        else
        {
            return dp[ind][buy] = max(prices[ind] + fMemo(ind + 2, 1, prices, dp), 0 + fMemo(ind + 1, 0, prices, dp));
        }
    }

public:
    int maxProfit2(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return fMemo(0, 1, prices, dp);
    }
};

// Using Tabulation...

class Solution_tab
{
public:
    int maxProfit_Tab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy == 1)
                {
                    dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
                }
                else
                {
                    dp[ind][buy] = max(prices[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};

// Using Space Optimization...
class Solution_SpaceOpti
{
public:
    int maxProfit_SpaceOpti(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> front2(2, 0);
        vector<int> front1(2, 0);
        vector<int> curr(2, 0);

        for (int ind = n - 1; ind >= 0; ind--)
        {
            curr[1] = max(-prices[ind] + front1[0], 0 + front1[1]);

            curr[0] = max(prices[ind] + front2[1], 0 + front1[0]);

            front2 = front1;
            front1 = curr;
        }
        return curr[1];
    }
};