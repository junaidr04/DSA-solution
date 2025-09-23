class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ans;
        if (words.empty())
            return ans;
        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int n = s.size();
        unordered_map<string, int> wordMp;
        for (string w : words)
        {
            wordMp[w]++;
        }
        for (int i = 0; i < wordLen; i++)
        {
            int left = i;
            int count = 0;
            unordered_map<string, int> seen;
            for (int right = i; right + wordLen <= n; right += wordLen)
            {
                string w = s.substr(right, wordLen);
                if (wordMp.find(w) != wordMp.end())
                {
                    seen[w]++;
                    count++;
                    while (seen[w] > wordMp[w])
                    {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                    if (count == wordCount)
                    {
                        ans.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                }
                else
                {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return ans;
    }
};