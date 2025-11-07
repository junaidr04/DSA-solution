// User function template for C++
class Solution
{
public:
    int search(string &pat, string &txt)
    {
        // code here
        vector<int> freqP(26, 0), freqT(26, 0);
        int p = pat.size(), t = txt.size();
        int l = 0, count = 0;
        for (char c : pat)
        {
            freqP[c - 'a']++;
        }
        for (int r = 0; r < t; r++)
        {
            freqT[txt[r] - 'a']++;
            while (r - l + 1 > p)
            {
                freqT[txt[l] - 'a']--;
                l++;
            }
            if (r - l + 1 == p)
            {
                if (freqP == freqT)
                {
                    count++;
                }
            }
        }
        return count;
    }
};