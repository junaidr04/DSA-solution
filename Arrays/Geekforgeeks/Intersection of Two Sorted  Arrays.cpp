class Solution
{
public:
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int i = 0, j = 0;
        vector<int> ans;
        while (i < arr1.size() && j < arr2.size())
        {
            if (arr1[i] == arr2[j])
            {
                if (ans.empty() || ans.back() != arr1[i])
                {
                    ans.push_back(arr1[i]);
                }
                i++;
                j++;
            }
            else if (arr1[i] < arr2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};