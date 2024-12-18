// Input : nums = [ 2, 3, -2, 4 ] Output : 6
#include <string>
#include <math.h>
#include <vector>
using namespace std;

// O(n) :

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxi = nums[0], mini = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
                swap(maxi, mini);
            maxi = max(nums[i], maxi * nums[i]);
            mini = min(nums[i], mini * nums[i]);
            res = max(res, maxi);
        }
        return res;
    }
};

// O(2*n)

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxi = INT_MIN;
        int p = 1;
        for (int i = 0; i < nums.size(); ++i)
        { // L->R
            p *= nums[i];
            maxi = max(maxi, p);
            if (p == 0)
                p = 1;
        }
        p = 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        { // R -> L
            p *= nums[i];
            maxi = max(maxi, p);
            if (p == 0)
                p = 1;
        }
        return maxi;
    }
};