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