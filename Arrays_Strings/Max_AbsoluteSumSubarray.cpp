// Input : nums = [ 1, -3, 2, 3, -4 ] Output : 5 Explanation : The subarray[2, 3] has absolute sum = abs(2 + 3) = abs(5) = 5.

//  Input : nums = [ 2, -5, 1, -4, 3, -2 ] Output : 8 Explanation : The subarray[-5, 1, -4] has absolute sum = abs(-5 + 1 - 4) = abs(-8) = 8.


// prefix sum method  O(n) 
class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int mini_pref = INT_MAX, max_pref = INT_MIN, pref_sum = 0, maxi = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            pref_sum += nums[i];
            mini_pref = min(mini_pref, pref_sum);
            max_pref = max(max_pref, pref_sum);
            if (pref_sum >= 0)
            {
                maxi = max(maxi, max(abs(pref_sum), abs(pref_sum - mini_pref)));
            }
            else
            {
                maxi = max(maxi, max(abs(pref_sum), abs(pref_sum - max_pref)));
            }
        }

        return maxi;
    }
};


// best greedy prefix sum solution

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int mini_pref = 0, max_pref = 0, pref_sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            pref_sum += nums[i];
            mini_pref = min(mini_pref, pref_sum);
            max_pref = max(max_pref, pref_sum);
        }

        return max_pref - mini_pref;
    }
};



// using kadanes algo

int maxAbsoluteSum(vector<int> &nums)
{
    int max_ending_here = 0, min_ending_here = 0;
    int max_sum = 0, min_sum = 0;

    for (int num : nums)
    {
        max_ending_here = max(num, max_ending_here + num);
        max_sum = max(max_sum, max_ending_here);   // max sum subarray

        min_ending_here = min(num, min_ending_here + num);
        min_sum = min(min_sum, min_ending_here);
    }
    return max(max_sum, abs(min_sum));
}