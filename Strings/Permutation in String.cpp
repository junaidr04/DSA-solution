class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> c1(26, 0);
        for (char c : s1)
            c1[c - 'a']++;
        vector<int> c2(26, 0);
        int window = s1.size();
        for (int i = 0; i < s2.size(); i++)
        {
            c2[s2[i] - 'a']++;
            if (i >= window)
            {
                c2[s2[i - window] - 'a']--;
            }
            if (c1 == c2)
                return true;
        }
        return false;
    }
};
