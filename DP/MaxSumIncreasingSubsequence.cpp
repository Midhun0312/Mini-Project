// Find the maximum sum subsequence of the given array such that the
//     integers in the subsequence are sorted in strictly increasing order
//         i.e.a strictly increasing subsequence.
//         Input : arr[] = [ 1, 101, 2, 3, 100 ] Output : 106

#include <string>
#include <math.h>
#include <iostream>
using namespace std;

int maxSumIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n);
    int maxi = -1;
    for (int i = 0; i < n; ++i)
    {
        dp[i] = arr[i];
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}