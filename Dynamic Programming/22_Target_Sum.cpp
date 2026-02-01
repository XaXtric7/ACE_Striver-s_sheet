#include <bits/stdc++.h>
using namespace std;

int findWays(vector<int> &num, int target)
{
    int n = num.size();
    vector<int> prev(target + 1, 0), curr(target + 1, 0);
    if (num[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    if (num[0] != 0 && num[0] <= target)
        prev[num[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= target; sum++)
        {
            int notTake = prev[sum];
            int take = 0;
            if (num[ind] <= sum)
                take = prev[sum - num[ind]];

            curr[sum] = (take + notTake);
        }
        prev = curr;
    }
    return prev[target];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int totSum = 0;
    for (auto it : arr)
        totSum += it;
    if (totSum - d < 0 || ((totSum - d) % 2))
        return false;
    return findWays(arr, (totSum - d) / 2);
}

int targetSum(int n, int target, vector<int> &arr)
{
    return countPartitions(n, target, arr);
}