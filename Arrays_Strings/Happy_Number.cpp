// Input : n = 19 
// Output : true 
// Explanation : 12 + 92 = 82 82 + 22 = 68 62 + 82 = 100 12 + 02 + 02 = 1








// Time Complexity : O(logN) where N is the number.
// Space Complexity : O(logN),
// Solved using Math + Hash Table.

class Solution
{
    int next_number(int n)
    {
        int t = 0;
        while (n != 0)
        {
            int digit = n % 10;
            t += digit * digit;
            n /= 10;
        }
        return t;
    }

public:
    bool isHappy(int n)
    {
        unordered_set<int> st;
        while (n != 1 && !st.count(n))
        {
            st.insert(n);
            n = next_number(n);
        }
        return n == 1;
    }
};