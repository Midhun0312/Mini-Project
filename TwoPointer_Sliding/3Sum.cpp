// hashing   - TLE

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; ++i)
    {
        set<int> mp;
        for (int j = i + 1; j < n; ++j)
        {
            int t = -(nums[i] + nums[j]);
            if (mp.find(t) != mp.end())
            {
                vector<int> v{nums[i], nums[j], t};
                sort(v.begin(), v.end());
                st.insert(v);
            }
            mp.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// optimal - 2 pointer.

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
                j++;
            else if (sum > 0)
                k--;
            else
            {
                vector<int> v = {nums[i], nums[j], nums[k]};
                ans.push_back(v);
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }
    return ans;
}
