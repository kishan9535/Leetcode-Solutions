class Solution {
public:
int n;
int t[201][201];
    int solve(int col,int row,vector<vector<int>>& grid){

        if(t[row][col]!=-1)return t[row][col];

        if(row==n-1) return grid[row][col];
      int res=INT_MAX;
      for(int ncol=0;ncol<n;ncol++){
        if(ncol!=col){
        res=min(res,solve(ncol,row+1,grid));
      }
      }
      return  t[row][col]=res+grid[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
       n=grid.size();
      int ans=INT_MAX;
      memset(t,-1,sizeof(t));
      for(int col=0;col<n;col++){
        ans=min(ans,solve(col,0,grid));
      }
      return ans;
    }
};