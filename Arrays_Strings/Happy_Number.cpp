// Input : n = 19 
// Output : true 
// Explanation : 12 + 92 = 82 82 + 22 = 68 62 + 82 = 100 12 + 02 + 02 = 1

// Time Complexity : O(logN) where N is the number.
// Space Complexity : O(1), Constant space.
// Solved using Floyd's Cycle-Finding Algorithm.


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
        int slow = n, fast = next_number(n);
        while (fast != 1 && slow != fast)
        {
            slow = next_number(slow);
            fast = next_number(next_number(fast));
        }
        return fast == 1;
    }
};

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