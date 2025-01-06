class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        int ending = points[0][1];
        int ans = 1;
        for (auto it : points)
        {
            if (it[0] > ending)
            {
                ans++;
                ending = it[1];
            }
            else
                ending = min(ending, it[1]);
        }
        return ans;
    }
};