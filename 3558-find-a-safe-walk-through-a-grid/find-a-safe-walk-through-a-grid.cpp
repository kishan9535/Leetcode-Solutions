class Solution {
public:
    int dir_r[4] = {1,-1,0,0};
    int dir_c[4] = {0,0,1,-1};
    int dp[51][51][102];
    bool recurs(vector<vector<int>>& grid, vector<vector<int>>& visited,int health,int i,int j){
        int n = grid.size(),m=grid[0].size();
        if(i==n-1&&j==m-1&&health-grid[i][j]>0)
            return 1;
        if(i>=n || j>=m || health<=0 || i<0 || j<0)
            return 0;

        if(dp[i][j][health] != -1)
            return dp[i][j][health];

        bool ans = false;

        for(int idx = 0;idx<4;idx++){
            int x = i+dir_r[idx],y = j+dir_c[idx];
            if(x<0||y<0||x>=n||y>=m||visited[x][y])
                continue;
            visited[x][y] = 1;
            ans |= recurs(grid,visited,health-grid[i][j],x,y);
            if(ans)
                return dp[i][j][health]=ans;
            visited[x][y] = 0;
        }
        return dp[i][j][health]=ans;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(),m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        return recurs(grid,visited,health,0,0);
    }
};