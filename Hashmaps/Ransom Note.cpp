class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> c2;
        for (char c : magazine)
        {
            c2[c]++;
        }
        for (char c : ransomNote)
        {
            if (c2[c] == 0)
            {
                return false;
            }
            c2[c]--;
        }
        return true;
    }
};