class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
       int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int waterTrapped = 0;
        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();
            int height = cell.first;
            int x = cell.second.first;
            int y = cell.second.second;
            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    waterTrapped += max(0, height - heightMap[nx][ny]);
                    pq.push({max(height, heightMap[nx][ny]), {nx, ny}});
                }
            }
        }

        return waterTrapped;  
    }
};