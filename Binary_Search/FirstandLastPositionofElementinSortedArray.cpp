// 1 -  Note: start < nums.size();

vector<int> searchRange(vector<int> &nums, int target)
{
    int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int end = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin() - 1;
    if (start < nums.size() && nums[start] == target)
        return {start, end};
    return {-1, -1};
}

// 2

class Solution
{
    int lower_bound(vector<int> &nums, int k)
    {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if (nums[mid] < k)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return lo;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = lower_bound(nums, target);
        int end = lower_bound(nums, target + 1) - 1;
        if (start < nums.size() && nums[start] == target)
            return {start, end};
        return {-1, -1};
    }
};