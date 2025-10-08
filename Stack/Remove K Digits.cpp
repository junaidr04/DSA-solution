class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        for (char digit : num)
        {
            while (!st.empty() && k > 0 && st.top() > digit)
            {
                st.pop();
                k--;
            }
            st.push(digit);
        }
        while (!st.empty() && k > 0)
        {
            st.pop();
            k--;
        }
        string result = "";
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        int i = 0;
        while (i < result.size() && result[i] == '0')
        {
            i++;
        }
        result = result.substr(i);
        if (result.empty())
        {
            return "0";
        }
        else
        {
            return result;
        }
    }
};