// Optimeized - O(n \log n + n \log(max\_distance))
// Binary Search + 2 pointer 



// TLE - O(n^2 \log k)

class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<int> pq; // maxheap
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                pq.push(abs(nums[i] - nums[j]));
                if (pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};