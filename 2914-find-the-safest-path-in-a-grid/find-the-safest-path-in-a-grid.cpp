class Solution {
public:
    int n;
    vector<vector<int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
    
    bool check_distance_to_Thief(vector<vector<int>>& Thief_dist, int safe) {
        queue<pair<int,int>> que;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        que.push({0,0});
        vis[0][0] = true;

        if (Thief_dist[0][0] < safe) {
            return false;
        }

        while (!que.empty()) {
            int curr_i = que.front().first;
            int curr_j = que.front().second;
            que.pop();
            if (curr_i == n-1 && curr_j == n-1) {
                return true;
            }

            for (auto& i : dir) {
                int new_i = curr_i + i[0];
                int new_j = curr_j + i[1];

                if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || vis[new_i][new_j]) {
                    continue;
                }
                if (Thief_dist[new_i][new_j] < safe) {
                    continue;
                }
                que.push({new_i, new_j});
                vis[new_i][new_j] = true;
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return 0;
        }

        vector<vector<int>> Thief_dist(n, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int,int>> que;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    que.push({i, j});
                    visited[i][j] = true;
                    Thief_dist[i][j] = 0;
                }
            }
        }

        while (!que.empty()) {
            int curr_i = que.front().first;
            int curr_j = que.front().second;
            que.pop();
            for (auto& i : dir) {
                int new_i = curr_i + i[0];
                int new_j = curr_j + i[1];

                if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || visited[new_i][new_j]) {
                    continue;
                }
                int new_dist = Thief_dist[curr_i][curr_j] + 1;
                if (new_dist < Thief_dist[new_i][new_j]) {
                    Thief_dist[new_i][new_j] = new_dist;
                    que.push({new_i, new_j});
                }
                visited[new_i][new_j] = true;
            }
        }

        int l = 0;
        int r = n * 2; // Adjust range based on potential maximum safeness factor
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check_distance_to_Thief(Thief_dist, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
