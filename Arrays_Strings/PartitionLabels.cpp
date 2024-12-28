// Input : s = "ababcbacadefegdehijhklij" Output : [ 9, 7, 8 ]
// partition the string into as many parts as possible so that each letter appears in at most one part.
// Note that the partition is done so that after concatenating all the parts in order, 
// the resultant string should be s.
// Return a list of integers representing the size of these parts.

#include <string>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.length();
        unordered_map<char, int> mp;
        for (int i = n - 1; i >= 0; --i)
        {
            if (mp.find(s[i]) == mp.end())
                mp[s[i]] = i;
        }
        vector<int> ans;
        int m = 0, b = 0;
        for (int i = 0; i < n; ++i)
        {
            if (m == mp[s[i]] && i == m)
            {
                ans.push_back(m - b + 1);
                b = m + 1;
                m++;
            }
            else
            {
                m = max(m, mp[s[i]]);
            }
        }
        return ans;
    }
};