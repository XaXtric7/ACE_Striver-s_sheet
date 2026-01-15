#include <bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int take = nums[i];
        if (i > 1)
            take += prev2;

        int notTake = prev;
        int curi = max(take, notTake);

        prev2 = prev;
        prev = curi;
    }
    return prev;
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
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        if (n == 1)
        {
            cout << nums[0] << endl;
            continue;
        }

        vector<int> temp1, temp2;

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]); // exclude first
            if (i != n - 1)
                temp2.push_back(nums[i]); // exclude last
        }

        int ans = max(
            maximumNonAdjacentSum(temp1),
            maximumNonAdjacentSum(temp2));

        cout << ans << endl;
    }
    return 0;
}
