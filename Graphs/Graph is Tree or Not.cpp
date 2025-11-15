class Solution
{
public:
    bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for (int nxt : adj[node])
        {
            if (nxt == parent)
                continue;
            if (vis[nxt])
                return true;
            if (dfs(nxt, node, adj, vis))
                return true;
        }
        return false;
    }
    int isTree(int n, int m, vector<vector<int>> &G)
    {
        if (m != n - 1)
            return 0;
        vector<int> adj[n];
        for (auto &e : G)
        {
            int u = e[0];
            int v = e[1];
            if (u == v)
                return 0;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        if (dfs(0, -1, adj, vis))
            return 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                return 0;
        }
        return 1;
    }
};
