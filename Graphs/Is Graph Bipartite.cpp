class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> setId(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (setId[i] != -1)
                continue;
            queue<int> q;
            q.push(i);
            setId[i] = 0;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v : graph[u])
                {
                    if (setId[v] == -1)
                    {
                        setId[v] = 1 - setId[u];
                        q.push(v);
                    }
                    else
                    {
                        if (setId[v] == setId[u])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};