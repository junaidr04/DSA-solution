class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> s;
        for (int c : nums)
        {
            if (s.find(c) != s.end())
            {
                return true;
            }
            s[c] = 1;
        }
        return false;
    }
};