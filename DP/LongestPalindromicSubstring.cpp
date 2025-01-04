










// expand around centre =   O(n^2) time and O(1) space

class Solution
{
    void func(int &st, int &l, string &s, int i, int j)
    {
        while (i >= 0 && j < s.length() && s[i] == s[j])
        {
            i--;
            j++;
        }
        if (l < j - i - 1)
        {
            l = max(l, j - i - 1);
            st = i + 1;
        }
    }

public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        int start_index = 0, length = 0;
        for (int i = 0; i < n; ++i)
        {
            func(start_index, length, s, i, i);
            func(start_index, length, s, i, i + 1);
        }
        return s.substr(start_index, length);
    }
};