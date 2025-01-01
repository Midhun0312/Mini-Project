class Solution
{
    void f(vector<int> &nums, vector<vector<int>> &ans, int id)
    {
        if (id == nums.size() - 1)
            ans.push_back(nums);
        for (int i = id; i < nums.size(); ++i)
        {
            swap(nums[id], nums[i]);
            f(nums, ans, id + 1);
            swap(nums[id], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        f(nums, ans, 0);
        return ans;
    }
};