class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            int curr = nums1[i];
            int nextGreat = -1;
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums2[j] == curr)
                {
                    for (int k = j + 1; k < nums2.size(); k++)
                    {
                        if (nums2[k] > curr)
                        {
                            nextGreat = nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
            ans.push_back(nextGreat);
        }
        return ans;
    }
};