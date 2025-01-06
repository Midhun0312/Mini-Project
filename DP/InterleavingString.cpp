// Input : s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output : true

// iterative 
// note the indexing (i<=m) , base cases.
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.length(), m = s2.length();
        if (n + m != s3.length())
            return false;
        bool dp[n + 1][m + 1];
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) // first row
            dp[0][i] = dp[0][i - 1] && (s2[i - 1] == s3[i - 1]);
        for (int j = 1; j <= n; ++j) // first col
            dp[j][0] = dp[j - 1][0] && (s1[j - 1] == s3[j - 1]);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[n][m];
    }
};

// recursive + memoized

class Solution
{
    int n, m;
    bool f(string &u, int i, string &v, int j, string &x, vector<vector<int>> &dp)
    {
        if (i == n && j == m)
            return true;
        if (dp[i][j] != -1)
            return dp[i][j];

        bool take_u = false, take_v = false;
        if (i < n && u[i] == x[i + j])
            take_u = f(u, i + 1, v, j, x, dp);
        if (j < m && v[j] == x[i + j])
            take_v = f(u, i, v, j + 1, x, dp);
        return dp[i][j] = take_u || take_v;
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        n = s1.length(), m = s2.length();
        if (n + m != s3.length())
            return false;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(s1, 0, s2, 0, s3, dp);
    }
};