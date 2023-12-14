class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
      int n=grid[0].size();
      int m=grid.size();
      vector<int>rows1(m,0);
      vector<int>cols1(n,0);
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              if(grid[i][j]==1){
                  rows1[i]++;
                  cols1[j]++;
              }
          }
      }
      vector<vector<int>> ans(m,vector<int>(n,0));
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
             int onesRowi =rows1[i];
             int onesColj=cols1[j];
             int zerosRowi =n-onesRowi;
             int zerosColj =m-onesColj;
             
             
             ans[i][j] = onesRowi + onesColj - zerosRowi - zerosColj;
 
          }
      } 
      return ans;
    }
};