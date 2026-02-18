#include <bits/stdc++.h>
using namespace std;

int longestStrChain(vector<string> &words)
{

    // Step 1: Sort words by length
    sort(words.begin(), words.end(), [](string &a, string &b)
         { return a.size() < b.size(); });

    unordered_map<string, int> dp;
    int maxi = 1;

    // Step 2: Traverse words
    for (auto word : words)
    {

        int best = 1; // minimum chain length

        // Step 3: Try removing one character
        for (int i = 0; i < word.size(); i++)
        {

            string prev = word.substr(0, i) + word.substr(i + 1);

            if (dp.find(prev) != dp.end())
            {
                best = max(best, dp[prev] + 1);
            }
        }

        dp[word] = best;
        maxi = max(maxi, best);
    }

    return maxi;
}

// Strive's sol...

bool checkPossible(string &s1, string &s2)
{
    // s1 should be exactly one character bigger than s2
    if (s1.size() != s2.size() + 1)
        return false;

    int first = 0;  // pointer for s1
    int second = 0; // pointer for s2

    while (first < s1.size())
    {
        if (second < s2.size() && s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
        {
            first++; // skip one char in s1
        }
    }

    return (second == s2.size());
}

int longestStrChain2(vector<string> &arr)
{

    int n = arr.size();

    // Sort by length
    sort(arr.begin(), arr.end(), [](string &a, string &b)
         { return a.size() < b.size(); });

    vector<int> dp(n, 1);
    int maxi = 1;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {

            if (checkPossible(arr[i], arr[prev]) &&
                dp[prev] + 1 > dp[i])
            {

                dp[i] = dp[prev] + 1;
            }
        }

        maxi = max(maxi, dp[i]);
    }

    return maxi;
}