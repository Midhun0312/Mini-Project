// Input : gas = [ 1, 2, 3, 4, 5 ], cost = [ 3, 4, 5, 1, 2 ] Output : 3

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int total = 0, tank = 0, start = 0;
        for (int i = 0; i < n; ++i)
        {
            total += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            if (tank < 0)
            {
                start = i + 1;
                tank = 0;
            }
        }
        return (total < 0) ? -1 : start;
    }
};