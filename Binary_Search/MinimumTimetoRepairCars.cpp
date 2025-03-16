// given an integer array ranks representing the ranks of some mechanics.ranksi is the rank of the ith mechanic.A mechanic with a rank r can repair n cars in r *n2 minutes.

//     You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

//     Return the minimum time taken to repair all the cars.

//     Note : All the mechanics can repair the cars simultaneously.

//            Example 1 :

//     Input : ranks = [ 4, 2, 3, 1 ],
//             cars = 10 Output : 16

class Solution
{
    bool check(long long x, vector<int> &ranks, int k)
    {
        long long ct = 0;
        for (int i = 0; i < ranks.size(); ++i)
        {
            ct += (long long)sqrt(x / ranks[i]);
            if (ct >= k)
                return true;
        }
        return false;
    }

public:
    long long repairCars(vector<int> &ranks, int cars)
    {
        int n = ranks.size();
        sort(ranks.begin(), ranks.end());
        long long lo = 0;
        long long hi = (long long)ranks[n - 1] * cars * cars;
        long long ans = hi;
        while (lo <= hi)
        {
            long long mid = (lo + hi) / 2;
            if (check(mid, ranks, cars))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};