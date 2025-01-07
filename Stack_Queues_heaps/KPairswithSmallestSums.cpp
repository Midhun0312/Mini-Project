// Return the k pairs(u1, v1), (u2, v2), ..., (uk, vk)with the smallest sums.

 // K * log(N)

typedef pair<int, int> pii;

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> ans;
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
        for (int i = 0; i < nums1.size(); ++i)
        {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }
        while (!pq.empty() && k--)
        {
            auto [s, pt] = pq.top();
            int x = pt.first, y = pt.second;
            pq.pop();
            ans.push_back({nums1[x], nums2[y]});
            if (y + 1 < nums2.size())
            {
                pq.push({nums1[x] + nums2[y + 1], {x, y + 1}});
            }
        }
        return ans;
    }
};