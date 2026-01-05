#include <bits\stdc++.h>
using namespace std;

// Space Optimized DP, TC = O(N), SC = O(1)
int climbStairs(int n)
{
    if (n <= 1)
        return 1;

    int prev2 = 1, prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

/*
Memoization, TC = O(N), SC = O(N)

class Solution {
private:
    int f(int n, vector<int>& dp) {
        if (n <= 1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = f(n-1, dp) + f(n-2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};

*/

int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n);
    return 0;
}
