class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st;
        for (auto it : nums)
            st.insert(it);
        int maxi = 0;
        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int x = it, ct = 1;
                while (st.find(x + 1) != st.end())
                {
                    x++;
                    ct++;
                }
                maxi = max(maxi, ct);
            }
        }
        return maxi;
    }
};