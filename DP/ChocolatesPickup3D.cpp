// Robot #1 is located at the top - left corner(0, 0), and
//  Robot #2 is located at the top - right corner(0, cols - 1).
// Return the maximum number of chocolates collection
//  n = 4,
//  m = 3 grid = [ [ 3, 1, 1 ], [ 2, 5, 1 ], [ 1, 5, 5 ], [ 2, 1, 1 ] ]
//  Output : 24

#include <string>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

int solve(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    for (int j1 = 0; j1 < m; ++j1)
    { // last row
        for (int j2 = 0; j2 < m; ++j2)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j1 = 0; j1 < m; ++j1)
        {
            for (int j2 = 0; j2 < m; ++j2)
            {
                int maxi = INT_MIN;
                // 9 possibility
                for (int d1 = -1; d1 <= 1; d1++)
                {
                    for (int d2 = -1; d2 <= 1; d2++)
                    {
                        int ans;
                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        if (j1 + d1 < 0 || j2 + d2 < 0 || j1 + d1 >= m || j2 + d2 >= m)
                            ans += -1e9;
                        else
                            ans += dp[i + 1][j1 + d1][j2 + d2];

                        maxi = max(maxi, ans);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m - 1];
}
