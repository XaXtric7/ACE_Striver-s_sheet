#include <bits/stdc++.h>
using namespace std;

int f(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int pick = nums[ind] + f(ind - 2, nums, dp);
    int notPick = 0 + f(ind - 1, nums, dp);

    return dp[ind] = max(pick, notPick);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        cout << f(n - 1, nums, dp) << "\n";
    }
    return 0;
}
/*
Spacce Optimiztion
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        int prev = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n; i++){
            int take = nums[i];
            if(i > 1) take += prev2;

            int notTake = 0 + prev;

            int curi = max(take, notTake);
            prev2 = prev;
            prev = curi;
        }
        cout << prev << "\n";
    }
    return 0;
}
*/