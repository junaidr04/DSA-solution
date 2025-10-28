class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> freq(26, 0);
        queue<pair<char, int>> q;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            freq[c - 'a']++;
            q.push({c, i});
            while (!q.empty() && freq[q.front().first - 'a'] > 1)
            {
                q.pop();
            }
        }
        if (!q.empty())
            return q.front().second;
        return -1;
    }
};