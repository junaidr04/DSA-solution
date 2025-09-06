class Solution
{
public:
    int getSecondLargest(vector<int> &arr)
    {
        int larg = INT_MIN;
        int Slarg = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > larg)
            {
                if (larg != INT_MIN)
                {
                    Slarg = larg;
                }
                larg = arr[i];
            }
            else if (arr[i] < larg && arr[i] > Slarg)
            {
                Slarg = arr[i];
            }
        }
        return Slarg;
    }
};