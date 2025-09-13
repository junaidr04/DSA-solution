class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int m = num1.size(), n = num2.size();
        vector<int> result(m + n, 0);
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int mul = ((num1[i] - '0') * (num2[j] - '0'));
                int pos1 = i + j;
                int pos2 = i + j + 1;
                int sum = mul + result[pos2];
                result[pos2] = sum % 10;
                result[pos1] += sum / 10;
            }
        }
        string ans = "";
        for (int num : result)
        {
            if (!(ans.empty() && num == 0))
            {
                ans.push_back(num + '0');
            }
        }
        if (ans.empty())
        {
            return "0";
        }
        else
        {
            return ans;
        }
    }
};