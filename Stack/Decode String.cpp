class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> numStack;
        stack<string> strStack;
        string curr = "";
        int num = 0;
        for (char c : s)
        {
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            else if (c == '[')
            {
                numStack.push(num);
                strStack.push(curr);
                curr = "";
                num = 0;
            }
            else if (c == ']')
            {
                string temp = curr;
                curr = strStack.top();
                strStack.pop();
                int times = numStack.top();
                numStack.pop();
                while (times--)
                    curr += temp;
            }
            else
            {
                curr += c;
            }
        }
        return curr;
    }
};