class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int s = grid.size();
        if (grid[0][0] == 1 || grid[s - 1][s - 1] == 1)
            return -1;
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            int dist = grid[x][y];
            if (x == s - 1 && y == s - 1)
                return dist;
            for (int i = 0; i < 8; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < s && ny < s && grid[nx][ny] == 0)
                {
                    grid[nx][ny] = dist + 1;
                    q.push({nx, ny});
                }
            }
        }
        return -1;
    }
};