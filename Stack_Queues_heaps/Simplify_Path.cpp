// Input : path = "/home/user/Documents/../Pictures" 
// Output : "/home/user/Pictures"

// Input : path = "/.../a/../b/c/../d/./"
// Output : "/.../b/d"

class Solution
{
public:
    string simplifyPath(string s)
    {
        string t = "";
        stack<string> st;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '/')
            {
                if (!t.empty())
                {
                    if (t == ".")
                    {
                        // dont do anything
                    }
                    else if (t == "..")
                    {
                        if (!st.empty())
                            st.pop();
                    }
                    else
                        st.push(t);
                    t = "";
                }
            }
            else
                t += s[i];
        }
        if (!t.empty())
        {
            if (t == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else if (t != ".")
                st.push(t);
        }
        string ans = "";
        while (!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans.empty() ? "/" : ans;
    }
};