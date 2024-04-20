class Solution {
public:
    int n, m;
   
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == 0) return 0;

        int amount = grid[i][j];
        // Mark the cell as visited
        grid[i][j] = 0;

        amount += dfs(grid, i + 1, j);
        amount += dfs(grid, i - 1, j);
        amount += dfs(grid, i, j + 1);
        amount += dfs(grid, i, j - 1);

        return amount;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};

