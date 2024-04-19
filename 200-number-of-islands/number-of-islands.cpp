class Solution {
public:
  int cnt;
  int m;
  int n;
   
    void dfs(vector<vector<char>>& grid,int i,int j){
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0' || grid[i][j]=='2') return;

    if(grid[i][j]=='1'){
        grid[i][j]='2';
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    return;
}

    int numIslands(vector<vector<char>>& grid) {
        cnt=0;
         m=grid.size();
         n=grid[0].size();

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    cnt++;
                }
            }
         }
         return cnt;
    }
};
