class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int num = nums.size();
        if (num == 0)
            return 0;
        int j = 0;
        for (int i = 0; i < num; i++)
        {
            if (nums[i] != nums[j])
            {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};