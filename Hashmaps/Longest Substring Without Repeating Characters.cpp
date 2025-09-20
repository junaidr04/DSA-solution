class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0, maxLen = 0;
        unordered_map<char, int> n;
        while (right < s.size())
        {
            if (n.find(s[right]) != n.end())
            {
                left = max(left, n[s[right]] + 1);
            }
            n[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};