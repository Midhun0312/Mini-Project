// Input : nums = [ 0, 1, 1, 1, 0, 1, 1, 0, 1 ] 
// Output : 5 
// Explanation : After deleting the number in position 4,
//         [ 0, 1, 1, 1, 1, 1, 0, 1 ] longest subarray with value of 1's is[1, 1, 1, 1, 1].

// Input : nums = [ 1, 1, 1 ] 
// Output : 2 Explanation : You must delete one element.

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 0, zeros = 0, ans = 0;
        while (j < n)
        {
            if (nums[j] == 0)
            {
                zeros++;
            }
            while (zeros > 1)
            {
                if (nums[i] == 0)
                    zeros--;
                i++;
            }
            ans = max(ans, j - i + 1 - zeros);
            j++;
        }

        return ans == n ? n - 1 : ans;
    }
};