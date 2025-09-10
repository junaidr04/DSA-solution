class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string result = "";
        int counter = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                if (counter > 0)
                    result += s[i];
                counter++;
            }
            else
            {
                counter--;
                if (counter > 0)
                    result += s[i];
            }
        }
        return result;
    }
};