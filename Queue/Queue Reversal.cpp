class Solution
{
public:
    void reverseQueue(queue<int> &q)
    {
        stack<int> s;
        while (!q.empty())
        {
            int ele = q.front();
            q.pop();
            s.push(ele);
        }
        while (!s.empty())
        {
            int ele = s.top();
            s.pop();
            q.push(ele);
        }
    }
};

// using recursion
class Solution
{
public:
    void reverseQueue(queue<int> &q)
    {
        if (q.empty())
            return;
        int ele = q.front();
        q.pop();
        reverseQueue(q);
        q.push(ele);
    }
};