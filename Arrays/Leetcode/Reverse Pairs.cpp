class Solution
{
public:
    void merge(vector<int> &nums, int left, int mid, int right)
    {
        vector<int> temp;
        int l = left, r = mid + 1;
        while (l <= mid && r <= right)
        {
            if (nums[l] <= nums[r])
            {
                temp.push_back(nums[l++]);
            }
            else
            {
                temp.push_back(nums[r++]);
            }
        }
        while (l <= mid)
        {
            temp.push_back(nums[l++]);
        }
        while (r <= right)
        {
            temp.push_back(nums[r++]);
        }
        for (int i = left; i <= right; i++)
        {
            nums[i] = temp[i - left];
        }
    }
    int mergeSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return 0;
        int mid = (left + right) / 2;
        int count = 0;
        count += mergeSort(nums, left, mid);
        count += mergeSort(nums, mid + 1, right);
        int j = mid + 1;
        for (int i = left; i <= mid; i++)
        {
            while (j <= right && (long long)nums[i] > 2LL * nums[j])
            {
                j++;
            }
            count += (j - (mid + 1));
        }
        merge(nums, left, mid, right);
        return count;
    }
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};