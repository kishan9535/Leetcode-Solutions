class Solution {
public:
  int m,n;
  unordered_map<int,vector<vector<int>>>dir={
    {1,{{0,-1},{0,1}}},
    {2,{{1,0},{-1,0}}},
    {3,{{1,0},{0,-1}}},
    {4,{{0,1},{1,0}}},
    {5,{{0,-1},{-1,0}}},
    {6,{{-1,0},{0,1}}}
  };

   bool dfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int i,int j){
    
    if(i==m-1 && j==n-1)return true;

    vis[i][j]=true;

    for(auto &it: dir[grid[i][j]]){
        int ni=it[0]+i;
        int nj=it[1]+j;

        if(ni<0 ||ni>=m ||nj<0||nj>=n || vis[ni][nj]){
            continue;
        }

        for(auto &back:dir[grid[ni][nj]]){
            if(ni+back[0]==i && nj+back[1]==j){
                if(dfs(grid,vis,ni,nj)){
                    return true;
                }
            }
        }
    }
    
    return false;

   }

    
    bool hasValidPath(vector<vector<int>>& grid) {
        n=grid[0].size();
        m=grid.size();

       vector<vector<bool>>vis(m,vector<bool>(n,false));
        return dfs(grid,vis,0,0);
    }
};