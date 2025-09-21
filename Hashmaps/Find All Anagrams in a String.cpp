class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        if (p.size() > s.size())
            return ans;
        vector<int> sc(26, 0), pc(26, 0);
        for (int c : p)
        {
            pc[c - 'a']++;
        }
        for (int i = 0; i < p.size(); i++)
        {
            sc[s[i] - 'a']++;
        }
        if (pc == sc)
            ans.push_back(0);
        for (int i = p.size(); i < s.size(); i++)
        {
            sc[s[i] - 'a']++;
            sc[s[i - p.size()] - 'a']--;
            if (pc == sc)
                ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};