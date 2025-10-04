class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> lastIndex(26, 0);
        vector<bool> seen(26, false);
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
            lastIndex[s[i] - 'a'] = i;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (seen[c - 'a'])
                continue;
            while (!st.empty() && st.top() > c &&
                   i < lastIndex[st.top() - 'a'])
            {
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            seen[c - 'a'] = true;
        }
        string result = "";
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};