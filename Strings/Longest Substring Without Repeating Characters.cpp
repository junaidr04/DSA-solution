class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0, maxLen = 0;
        unordered_set<char> n;
        while (right < s.size())
        {
            if (n.find(s[right]) == n.end())
            {
                n.insert(s[right]);
                maxLen = max(maxLen, (int)n.size());
                right++;
            }
            else
            {
                n.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};