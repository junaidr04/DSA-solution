class Solution
{
public:
    vector<int> calculateSpan(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> span(n);
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top().first <= arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                span[i] = i + 1;
            }
            else
            {
                span[i] = i - st.top().second;
            }
            st.push({arr[i], i});
        }
        return span;
    }
};