// return an array answer such that answer[i] is the number of days you have to wait
//  after the ith day to get a warmer temperature. If there is no future day for which this is possible, 
//  keep answer[i] == 0 instead.

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temp)
    {
        stack<int> st;
        int n = temp.size();
        vector<int> ans(n, 0);
        st.push(n - 1);
        for (int i = n - 2; i >= 0; --i)
        {
            while (!st.empty() && temp[st.top()] <= temp[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};