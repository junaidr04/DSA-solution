class Solution
{
public:
    int longestValidSubstring(string word, vector<string> &forbidden)
    {
        int left = 0, right = 0, ans = 0;
        unordered_set<string> bad(forbidden.begin(), forbidden.end());
        for (int right = 0; right < word.size(); right++)
        {
            for (int len = 1; len <= 10 && right - len + 1 >= left; len++)
            {
                string now = word.substr(right - len + 1, len);
                if (bad.count(now))
                {
                    left = right - len + 2;
                    break;
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};