class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &t : times)
        {
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u])
                continue;
            for (auto &e : adj[u])
            {
                int v = e.first, w = e.second;
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INT_MAX)
                return -1;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};