// Input : tokens = [ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" ]
//  Output : 22 
//  Explanation : ((10 * (6 / ((9 + 3) * -11))) + 17) + 5 
//                             = ((10 * (6 / (12 * -11))) + 17) + 5 
//                             = ((10 * (6 / -132)) + 17) + 5 
//                             = ((10 * 0) + 17) + 5 
//                             = (0 + 17) + 5
//                             = 17 + 5
//                             = 22

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (auto it : tokens)
        {
            if (it == "+")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a + b);
            }
            else if (it == "-")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a - b);
            }
            else if (it == "*")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a * b);
            }
            else if (it == "/")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a / b);
            }
            else
            {
                int t = stoi(it);
                st.push(t);
            }
        }
        return st.top();
    }
};