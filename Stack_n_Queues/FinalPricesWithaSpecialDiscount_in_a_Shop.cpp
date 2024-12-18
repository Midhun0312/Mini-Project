// There is a special discount for items in the shop.
// If you buy the ith item, then you will receive a discount equivalent to prices[j]
//  where j is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise,
//   you will not receive any discount at all.
// Input: prices = [8,4,6,2,3]
// Output: [4,2,4,2,3]

#include <string>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

// O(n) 

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> ans(n);
        ans[n - 1] = prices[n - 1];
        stack<int> st;
        st.push(prices[n - 1]);
        for (int i = n - 2; i >= 0; --i)
        {
            while (!st.empty() && st.top() > prices[i])
            {
                st.pop();
            }
            if (!st.empty())
                ans[i] = prices[i] - st.top();
            else
                ans[i] = prices[i];
            st.push(prices[i]);
        }
        return ans;
    }
};