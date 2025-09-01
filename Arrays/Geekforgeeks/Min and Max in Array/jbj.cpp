class Solution
{
public:
    pair<int, int> getMinMax(vector<int> arr)
    {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            int x = arr[i];
            if (x < mini)
                mini = x;
            if (x > maxi)
                maxi = x;
        }
        return {mini, maxi};
    }
};