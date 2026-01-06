#include <bits\stdc++.h>
using namespace std;

// Greedy will fail, [Recursion method] (gives TLE for large values)
// TC = O(2^n), SC = O(n)

/*
int f(int ind, vector<int> &heights)
{
    if (ind == 0)
        return 0;

    int left = f(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
    {
        right = f(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);
    }
    return min(left, right);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
        }
        cout << f(n - 1, heights);
    }
    return 0;
}
*/

// Memoization for optimization
// TC = O(n), SC = O(n)  (dp + recursion stack)

/*
int f(int ind, vector<int> &heights, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int left = f(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
    {
        right = f(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    }
    return dp[ind] = min(left, right);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> heights(n);
        vector<int> dp(n, -1); // dp-array
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
        }
        cout << f(n - 1, heights, dp);
    }
    return 0;
}
*/

// Recursion --> Tabulation
// TC = O(n), SC = O(n)

/*
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
        }

        // main solution through [Tabulation]

        vector<int> dp(n, -1); // dp-array
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            int ss = INT_MAX;
            if (i > 1)
            {
                ss = dp[i - 2] + abs(heights[i] - heights[i - 2]);
            }
            dp[i] = min(fs, ss);
        }
        cout << dp[n - 1];
    }
    return 0;
}
*/

// Tabulation --> Space optimization
// TC = O(n), SC = O(1)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
        }

        // main solution through [Tabulation -> Space optimization]

        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int i = 1; i < n; i++)
        {
            int fs = prev1 + abs(heights[i] - heights[i - 1]);
            int ss = INT_MAX;
            if (i > 1)
                ss = prev2 + abs(heights[i] - heights[i - 2]);

            int cur = min(fs, ss);
            prev2 = prev1;
            prev1 = cur;
        }

        cout << prev1;
    }
    return 0;
}