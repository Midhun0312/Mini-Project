// Input : startGene = "AACCGGTT",
//  endGene = "AAACGGTA", 
//  bank = [ "AACCGGTA", "AACCGCTA", "AAACGGTA" ] 
//  Output : 2

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        unordered_set<string> st(bank.begin(), bank.end());
        if (!st.count(endGene))
            return -1;
        queue<string> q;
        q.push(startGene);
        int steps = 0;
        while (!q.empty())
        {
            int t = q.size();
            while (t--)
            {
                string s = q.front();
                q.pop();
                if (s == endGene)
                    return steps;
                st.erase(s);
                for (int i = 0; i < 8; ++i)
                {
                    string u = s;
                    u[i] = 'A';
                    if (st.count(u))
                        q.push(u);
                    u[i] = 'C';
                    if (st.count(u))
                        q.push(u);
                    u[i] = 'G';
                    if (st.count(u))
                        q.push(u);
                    u[i] = 'T';
                    if (st.count(u))
                        q.push(u);
                }
            }
            steps++;
        }
        return -1;
    }
};