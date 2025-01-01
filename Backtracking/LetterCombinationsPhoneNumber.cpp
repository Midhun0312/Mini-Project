class Solution
{
    void f(vector<string> &ans, unordered_map<int, vector<char>> &mp, string d, int id, string t)
    {
        int v = d[id] - '0';
        if (id == d.length() - 1)
        {
            for (auto it : mp[v])
            {
                ans.push_back(t + it);
            }
        }
        else
        {
            for (auto it : mp[v])
            {
                f(ans, mp, d, id + 1, t + it);
            }
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() == 0)
            return ans;
        unordered_map<int, vector<char>> mp;
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};

        string t = "";
        f(ans, mp, digits, 0, t);
        return ans;
    }
};