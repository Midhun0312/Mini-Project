// Input : Str = “aabbcc”, k = 2
// Output : 4
// Explanation : Max substring can be any one from{“aabb”, “bbcc”}.

// C++

int longestKSubstr(string s, int k)
{
    int i = 0;
    int j = 0;
    int ans = -1;
    unordered_map<char, int> mp;
    while (j < s.size())
    {
        mp[s[j]]++;
        while (mp.size() > k)
        {
            mp[s[i]]--;
            if (mp[s[i]] == 0)
                mp.erase(s[i]);
            i++;
        }
        if (mp.size() == k)
        {
            ans = max(ans, j - i + 1);
        }
        j++;
    }
    return ans;
}
