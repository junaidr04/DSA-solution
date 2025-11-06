class Solution
{
public:
    int countPairs(vector<int> &nums, int mid)
    {
        int count = 0, j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (j < nums.size() && nums[j] - nums[i] <= mid)
            {
                j++;
                count += j - i - 1;
            }
        }
        return count;
    }
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums.front();
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (countPairs(nums, mid) >= k)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};