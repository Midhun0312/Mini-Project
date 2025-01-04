class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &ob)
    {
        int m = ob.size(), n = ob[0].size();
        if (ob[0][0] || ob[m - 1][n - 1])
            return 0;
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            if (ob[0][i])
                dp[i] = 0;
            else
                dp[i] = dp[i - 1];
        }
        for (int i = 1; i < m; ++i)
        {
            if (ob[i][0])
                dp[0] = 0;
            for (int j = 1; j < n; ++j)
            {
                if (ob[i][j])
                    dp[j] = 0;
                else
                    dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};