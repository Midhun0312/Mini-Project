// 2182
// You are given a string s and an integer repeatLimit.Construct a new string repeatLimitedString using
//  the characters of s such that no letter appears more than repeatLimit times in a row.
//  You do not have to use all characters from s. Return the lexicographically largest repeatLimitedString possible.

// Input : s = "cczazcc", repeatLimit = 3 Output : "zzcccac"

class Solution
{
public:
    string repeatLimitedString(string s, int k)
    {
        int a[26] = {};
        string t = "";
        for (int i = 0; i < s.length(); ++i)
        {
            a[s[i] - 'a']++;
        }

        int i = 25, j = 24;
        while (i >= 0 && a[i] == 0)
            i--;
        j = i - 1;
        while (j >= 0 && a[j] == 0)
            j--;

        while (i >= 0)
        {
            int count = min(a[i], k);
            for (int r = 0; r < count; ++r)
            {
                t += i + 'a';
            }
            a[i] -= count;
            if (a[i] > 0)
            {
                if (j < 0)
                    break;
                t += j + 'a';
                a[j]--;
                while (j >= 0 && a[j] == 0)
                    j--;
            }
            else
            {
                i--;
                while (i >= 0 && a[i] == 0)
                    i--;
                j = i - 1;
                while (j >= 0 && a[j] == 0)
                    j--;
            }
        }

        return t;
    }
};
