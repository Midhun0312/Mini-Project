class Solution
{
    void f(vector<vector<int>> &ans, vector<int> &v, int n, int k, int start)
    {
        if (k == 0)
        {
            ans.push_back(v);
            return;
        }
        for (int i = start; i <= n; ++i)
        {
            v.push_back(i);
            f(ans, v, n, k - 1, i + 1);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> v;
        f(ans, v, n, k, 1);
        return ans;
    }
};