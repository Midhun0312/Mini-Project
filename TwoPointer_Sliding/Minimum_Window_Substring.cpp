// tc - O(n+m) 
// sc = O(m);

// Given two strings s and t of lengths m and n respectively, return the minimum 
// window substring of s such that every character in t(including duplicates) is included in the window.
// If there is no such substring, return the empty string "".

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length(), m = t.length();
        if (n < m)
            return "";
        int st = 0, mini = 1e9, ct = 0;
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        for (auto it : t)
            mp[it]++;

        while (j < n)
        {
            if (mp.find(s[j]) != mp.end())
            {
                if (mp[s[j]] > 0)
                    ct++;
            }
            mp[s[j]]--;
            while (ct == m)
            {
                if (mini > j - i + 1)
                {
                    mini = j - i + 1;
                    st = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                    ct--;
                i++;
            }
            j++;
        }

        return mini == 1e9 ? "" : s.substr(st, mini);
    }
};