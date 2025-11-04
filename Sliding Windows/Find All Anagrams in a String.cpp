class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        if (p.size() > s.size())
            return ans;
        unordered_map<char, int> sc, pc;
        for (char c : p)
        {
            pc[c]++;
        }
        for (int i = 0; i < p.size(); i++)
        {
            sc[s[i]]++;
        }
        if (pc == sc)
            ans.push_back(0);
        for (int i = p.size(); i < s.size(); i++)
        {
            sc[s[i]]++;
            sc[s[i - p.size()]]--;
            if (sc[s[i - p.size()]] == 0)
            {
                sc.erase(s[i - p.size()]);
            }
            if (pc == sc)
            {
                ans.push_back(i - p.size() + 1);
            }
        }
        return ans;
    }
};