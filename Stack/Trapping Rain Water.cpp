class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0, right = height.size() - 1, leftMax = 0, rightMax = 0, ans = 0;
        while (left < right)
        {
            if (height[left] <= height[right])
            {
                if (leftMax < height[left])
                {
                    leftMax = height[left];
                }
                else
                {
                    ans += leftMax - height[left];
                    left++;
                }
            }
            else
            {
                if (rightMax < height[right])
                {
                    rightMax = height[right];
                }
                else
                {
                    ans += rightMax - height[right];
                    right--;
                }
            }
        }
        return ans;
    }
};