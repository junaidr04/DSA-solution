class Solution
{
public:
    string countAndSay(int n)
    {
        string result = "1";
        for (int i = 1; i < n; i++)
        {
            string temp = "";
            int count = 1;
            for (int j = 0; j < result.size(); j++)
            {
                if (result[j] == result[j + 1])
                {
                    count++;
                }
                else
                {
                    temp += to_string(count);
                    temp += result[j];
                    count = 1;
                }
            }
            result = temp;
        }
        return result;
    }
};