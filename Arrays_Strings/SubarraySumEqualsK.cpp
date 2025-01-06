// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non -empty sequence of elements within an array.
// Example 1 :
// Input : nums = [ 1, 1, 1 ],
// k = 2 Output : 2

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <numeric>
#include <cstddef>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int ct = 0, s = 0;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            s += nums[i]; // pref[R] - pref[L] = k
            if (mp.find(s - k) != mp.end())
            {
                ct += mp[s - k];
            }
            mp[s]++;
        }
        return ct;
    }
};
