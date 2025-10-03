class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> a;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[')
            {
                a.push(ch);
            }
            else
            {
                if (!a.empty())
                {
                    char top = a.top();
                    if ((ch == ')' && top == '(') ||
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '['))
                    {
                        a.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return a.empty();
    }
};