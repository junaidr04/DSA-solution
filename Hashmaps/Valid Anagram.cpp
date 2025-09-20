class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> n;
        for (char c : s)
        {
            n[c]++;
        }
        for (char c : t)
        {
            n[c]--;
            if (n[c] < 0)
                return false;
        }
        return true;
    }
};