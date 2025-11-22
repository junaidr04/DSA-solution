class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        priority_queue<int> q;
        for (int s : arr)
        {
            q.push(s);
            if (q.size() > k)
            {
                q.pop();
            }
        }
        return q.top();
    }
};