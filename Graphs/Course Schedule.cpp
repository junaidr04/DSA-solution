class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites)
        {
            int a = p[0], b = p[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            count++;
            for (int nxt : adj[course])
            {
                indegree[nxt]--;
                if (indegree[nxt] == 0)
                {
                    q.push(nxt);
                }
            }
        }
        return count == numCourses;
    }
};