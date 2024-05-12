class Solution {
public:
    int Find_Maxi_RCB(int i,int j,vector<vector<int>>& grid){
      int maxi=INT_MIN;
      int n=grid.size();
      for(int k=i;k<i+3;k++){
        for(int h=j;h<j+3;h++){
            maxi=max(maxi,grid[k][h]);
        }
      }
      return maxi;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>ans(n-2,vector<int>(n-2));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                ans[i][j]=Find_Maxi_RCB(i,j,grid);
            }
        }
        return ans;
    }
};