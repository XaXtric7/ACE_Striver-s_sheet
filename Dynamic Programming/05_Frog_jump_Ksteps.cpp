#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, int k, vector<int> &heights)
{
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
            }
        }
    }
    return dp[n - 1];
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
        cin >> heights[i];

    cout << frogJump(n, k, heights);
    return 0;
}
