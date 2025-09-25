class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        int maxLen = 0, sum = 0;
        freq[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                sum += -1;
            }
            else
            {
                sum += 1;
            }
            if (freq.find(sum) != freq.end())
            {
                maxLen = max(maxLen, i - freq[sum]);
            }
            else
            {
                freq[sum] = i;
            }
        }
        return maxLen;
    }
};