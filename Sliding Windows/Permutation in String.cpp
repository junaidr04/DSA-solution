class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> c1;
        for (char c : s1)
        {
            c1[c]++;
        }
        unordered_map<char, int> c2;
        int window = s1.size();
        for (int i = 0; i < s2.size(); i++)
        {
            c2[s2[i]]++;
            if (i >= window)
            {
                c2[s2[i - window]]--;
                if (c2[s2[i - window]] == 0)
                {
                    c2.erase(s2[i - window]);
                }
            }
            if (c1 == c2)
                return true;
        }
        return false;
    }
};
