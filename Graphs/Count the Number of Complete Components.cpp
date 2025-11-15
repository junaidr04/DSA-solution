class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &comp)
    {
        vis[node] = 1;
        comp.push_back(node);
        for (int nxt : adj[node])
        {
            if (!vis[nxt])
                dfs(nxt, adj, vis, comp);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vector<int> adj[n];
        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                vector<int> comp;
                dfs(i, adj, vis, comp);
                int edge_count = 0;
                for (int u : comp)
                {
                    for (int v : adj[u])
                    {
                        if (find(comp.begin(), comp.end(), v) != comp.end())
                            edge_count++;
                    }
                }
                edge_count /= 2;
                int k = comp.size();
                if (edge_count == k * (k - 1) / 2)
                    ans++;
            }
        }
        return ans;
    }
};