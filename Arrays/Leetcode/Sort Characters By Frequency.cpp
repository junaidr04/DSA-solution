class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }
        string result = "";
        while (!freq.empty())
        {
            char maxChar;
            int maxFreq = 0;
            for (auto &p : freq)
            {
                if (p.second > maxFreq)
                {
                    maxFreq = p.second;
                    maxChar = p.first;
                }
            }
            result += string(maxFreq, maxChar);
            freq.erase(maxChar);
        }
        return result;
    }
};