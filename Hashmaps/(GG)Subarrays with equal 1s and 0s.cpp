class Solution
{
public:
    int countSubarray(vector<int> &arr)
    {
        // code here
        unordered_map<int, int> freq;
        int count = 0, sum = 0;
        freq[0] = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                sum += -1;
            }
            else
            {
                sum += 1;
            }
            if (freq.find(sum) != freq.end())
            {
                count += freq[sum];
            }
            freq[sum]++;
        }
        return count;
    }
};