class Solution
{
public:
    int largest(vector<int> &arr)
    {
        // code here
        int maxVal = arr[0];
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > maxVal)
            {
                maxVal = arr[i];
            }
        }
        return maxVal;
    }
};
