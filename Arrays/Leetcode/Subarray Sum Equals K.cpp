// Time complexity = 0(n^2)

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum == k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

// ime complexity = 0(n)

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int prefixSum = 0, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            int rmv = prefixSum - k;
            count += mpp[rmv];
            mpp[prefixSum] += 1;
        }
        return count;
    }
};