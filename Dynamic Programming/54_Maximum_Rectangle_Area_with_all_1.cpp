#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &height)
{
    int n = height.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= n; i++)
    {
        int currHeight = (i == n) ? 0 : height[i];

        while (!st.empty() && currHeight < height[st.top()])
        {
            int h = height[st.top()];
            st.pop();

            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            maxArea = max(maxArea, h * width);
        }

        st.push(i);
    }

    return maxArea;
}

int maximalAreaOfSubMatrixOfAll(vector<vector<int>> &mat, int n, int m)
{
    int maxArea = 0;
    vector<int> height(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
                height[j]++;
            else
                height[j] = 0;
        }
        int area = largestRectangleArea(height);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}