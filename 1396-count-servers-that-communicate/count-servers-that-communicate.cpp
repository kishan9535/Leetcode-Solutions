class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
      int ans=0;
      int m=grid.size();
      int n=grid[0].size();
       vector<int>row_cnt(m,0);
       vector<int>col_cnt(n,0);
      for(int row=0;row<m;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col]==1){
                row_cnt[row]++;
                col_cnt[col]++;
            }
        }
      }

      for(int row=0;row<m;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col]==1 && (row_cnt[row]>1 || col_cnt[col]>1)){
                ans++;
            }
        }
      }
      return ans; 
    }
};