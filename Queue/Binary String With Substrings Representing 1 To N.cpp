class Solution
{
public:
    bool queryString(string s, int n)
    {
        for (int i = 1; i <= n; i++)
        {
            string bin = bitset<32>(i).to_string();
            bin = bin.substr(bin.find('1'));
            if (s.find(bin) == string::npos)
            {
                return false;
            }
        }
        return true;
    }
};