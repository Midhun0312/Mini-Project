// Given a m x n grid filled with non - negative numbers, find a path from top left 
// to bottom right, which minimizes the sum of all numbers along its path.
//  Note : You can only move either down or right at any point in time.

#include <string>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

// TC -> O(n2)  ,  SC -> O(n2);

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = grid[0][0];
    for (int j = 1; j < m; ++j)
    {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (int j = 1; j < n; ++j)
    {
        dp[j][0] = dp[j - 1][0] + grid[j][0];
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}


// SC -> O(n)

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<int> dp(m);
    dp[0] = grid[0][0];
    for (int i = 1; i < m; ++i)
        dp[i] = dp[i - 1] + grid[0][i];
    for (int i = 1; i < n; ++i)
    {
        dp[0] += grid[i][0];
        for (int j = 1; j < m; ++j)
        {
            dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
        }
    }
    return dp[m - 1];
}
