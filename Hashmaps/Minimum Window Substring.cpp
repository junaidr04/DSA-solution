class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty())
            return "";
        unordered_map<char, int> target;
        for (char c : t)
        {
            target[c]++;
        }
        unordered_map<char, int> windowCounts;
        int left = 0, minLen = INT_MAX, minStart = 0, formed = 0;
        for (int right = 0; right < s.size(); right++)
        {
            windowCounts[s[right]]++;
            if (target.count(s[right]) && windowCounts[s[right]] == target[s[right]])
            {
                formed++;
            }
            while (formed == target.size())
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    minStart = left;
                }
                char d = s[left];
                windowCounts[d]--;
                if (target.count(d) && windowCounts[d] < target[d])
                {
                    formed--;
                }
                left++;
            }
        }
        if (minLen == INT_MAX)
            return "";
        else
            return s.substr(minStart, minLen);
    }
};