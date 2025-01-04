int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> prev(n, INT_MAX), curr(n, INT_MAX);
    prev[0] = triangle[0][0];

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j - 1 >= 0)
                curr[j] = min(prev[j], prev[j - 1]) + triangle[i][j];
            else
                curr[j] = prev[j] + triangle[i][j];
        }
        prev = curr;
    }

    int mini = INT_MAX;
    for (int i = 0; i < n; ++i)
        mini = min(mini, prev[i]);
    return mini;
}