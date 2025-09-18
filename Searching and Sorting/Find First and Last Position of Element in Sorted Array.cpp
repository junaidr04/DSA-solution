class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = findFirst(nums, target);
        int second = findSecond(nums, target);
        return {first, second};
    }
    int findFirst(vector<int> &nums, int target)
    {
        int s = 0, e = nums.size() - 1;
        int ans = -1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                e = mid - 1;
            }
            else if (nums[mid] < target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }
    int findSecond(vector<int> &nums, int target)
    {
        int s = 0, e = nums.size() - 1;
        int ans = -1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                s = mid + 1;
            }
            else if (nums[mid] < target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }
};