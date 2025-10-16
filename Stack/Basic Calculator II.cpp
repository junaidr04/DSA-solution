class Solution
{
public:
    int calculate(string s)
    {
        stack<int> st;
        long num = 0;
        char op = '+';
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1)
            {
                if (op == '+')
                    st.push(num);
                else if (op == '-')
                    st.push(-num);
                else if (op == '*')
                {
                    int temp = st.top();
                    st.pop();
                    st.push(temp * num);
                }
                else if (op == '/')
                {
                    int temp = st.top();
                    st.pop();
                    st.push(temp / num);
                }
                op = c;
                num = 0;
            }
        }
        int ans = 0;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};