// optimal .

class Solution
{
    void f(vector<vector<int>> &ans, vector<int> &v, vector<int> &c, int k, int id)
    {
        if (k == 0)
        {
            ans.push_back(v);
            return;
        }
        if (id == c.size() || k < 0)
            return;
        for (int i = id; i < c.size(); ++i)
        {
            if (c[i] > k)
                break;
            v.push_back(c[i]);
            f(ans, v, c, k - c[i], i);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &c, int target)
    {
        vector<vector<int>> ans;
        vector<int> v;
        sort(c.begin(), c.end());
        f(ans, v, c, target, 0);
        return ans;
    }
};

// O(2^n)
class Solution
{
    void f(vector<vector<int>> &ans, vector<int> &candidates, vector<int> &v, int id, int k)
    {
        if (k == 0)
        {
            ans.push_back(v);
            return;
        }
        if (k < 0 || id == candidates.size())
            return;
        // take
        v.push_back(candidates[id]);
        f(ans, candidates, v, id, k - candidates[id]);
        v.pop_back();
        // dont take
        f(ans, candidates, v, id + 1, k);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> v;
        vector<vector<int>> ans;
        f(ans, candidates, v, 0, target);
        return ans;
    }
};

