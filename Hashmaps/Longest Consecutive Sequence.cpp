class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        unordered_map<int, int> mp;
        int longest = 0;
        for (int num : nums)
        {
            if (mp.find(num) != mp.end())
                continue;
            int left = 0;
            if (mp.find(num - 1) != mp.end())
            {
                left = mp[num - 1];
            }
            int right = 0;
            if (mp.find(num + 1) != mp.end())
            {
                right = mp[num + 1];
            }
            int curLen = left + 1 + right;
            mp[num] = curLen;
            if (left > 0)
                mp[num - left] = curLen;
            if (right > 0)
                mp[num + right] = curLen;
            longest = max(longest, curLen);
        }
        return longest;
    }
};