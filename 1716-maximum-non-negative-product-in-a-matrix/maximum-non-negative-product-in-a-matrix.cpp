class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll> P;

    int m, n;
    int mod = 1e9 + 7;

    vector<vector<P>> dp;
    vector<vector<bool>> vis;

    P solve(int i, int j, vector<vector<int>>& grid) {

        if (i == m - 1 && j == n - 1) {
            return {grid[i][j], grid[i][j]};
        }

        if (vis[i][j]) return dp[i][j];
        vis[i][j] = true;

        ll maxi = LLONG_MIN;
        ll mini = LLONG_MAX;

      
        if (i + 1 < m) {
            P tmp = solve(i + 1, j, grid);
            ll a = tmp.first * grid[i][j];
            ll b = tmp.second * grid[i][j];
            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        
        if (j + 1 < n) {
            P tmp = solve(i, j + 1, grid);
            ll a = tmp.first * grid[i][j];
            ll b = tmp.second * grid[i][j];
            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        return dp[i][j] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<P>(n));
        vis.assign(m, vector<bool>(n, false));

        P res = solve(0, 0, grid);

        if (res.first < 0) return -1;
        return res.first % mod;
    }
};