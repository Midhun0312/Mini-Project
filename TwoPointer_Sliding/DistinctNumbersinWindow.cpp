// Input 1 : A = [ 1, 2, 1, 3, 4, 3 ] B = 3

//           A = [ 1, 2, 1, 3, 4, 3 ] and B = 3 All windows of size B are
//               [1, 2, 1]
//               [2, 1, 3]
//               [1, 3, 4]
//               [3, 4, 3] So,
//           we return an array[2, 3, 3, 2].

#include <string>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> Solution::dNums(vector<int> &A, int B)
{
    vector<int> ans;
    int n = A.size();
    if (B > n)
        return ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < B; ++i)
    {
        mp[A[i]]++;
    }
    ans.push_back(mp.size());
    for (int i = 1; i + B - 1 < n; ++i)
    {
        mp[A[i - 1]]--;
        if (mp[A[i - 1]] == 0)
            mp.erase(A[i - 1]);
        mp[A[i + B - 1]]++;
        ans.push_back(mp.size());
    }
    return ans;
}
