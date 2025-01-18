class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
      int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> dq;

        dq.push_front({0, 0});
        cost[0][0] = 0;

        while (!dq.empty()) {
            auto [i, j] = dq.front();
            dq.pop_front();

            for (int d = 0; d < 4; d++) {
                int ni = i + dir[d][0];
                int nj = j + dir[d][1];
                int new_cost = cost[i][j] + (grid[i][j] - 1 != d);

                if (ni >= 0 && nj >= 0 && ni < n && nj < m && new_cost < cost[ni][nj]) {
                    cost[ni][nj] = new_cost;
                    if (grid[i][j] - 1 == d) {
                        dq.push_front({ni, nj});
                    } else {
                        dq.push_back({ni, nj});
                    }
                }
            }
        }

        return cost[n - 1][m - 1];   
    }
};