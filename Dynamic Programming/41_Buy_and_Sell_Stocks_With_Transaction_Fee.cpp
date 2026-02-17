#include <bits/stdc++.h>
using namespace std;

int maxProfit(int n, int fee, vector<int> &prices)
{
    int aheadNotBuy, aheadBuy, curBuy, curNotBuy;
    aheadBuy = aheadNotBuy = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        // buy
        curBuy = max(-prices[ind] - fee + aheadNotBuy, 0 + aheadBuy);

        // sell
        curNotBuy = max(prices[ind] - fee + aheadBuy, 0 + aheadNotBuy);

        aheadBuy = curBuy;
        aheadNotBuy = curNotBuy;
    }
    return aheadBuy;
}