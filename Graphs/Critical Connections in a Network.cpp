class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> timeIn, low;
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>> &adj)
    {
        timeIn[node] = low[node] = timer++;
        for (int nxt : adj[node])
        {
            if (nxt == parent)
                continue;
            if (timeIn[nxt] == 0)
            {
                dfs(nxt, node, adj);
                low[node] = min(low[node], low[nxt]);
                if (low[nxt] > timeIn[node])
                {
                    ans.push_back({node, nxt});
                }
            }
            else
            {
                low[node] = min(low[node], timeIn[nxt]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        for (auto &e : connections)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        timeIn.assign(n, 0);
        low.assign(n, 0);
        dfs(0, -1, adj);
        return ans;
    }
};