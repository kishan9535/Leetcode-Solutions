class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
      int m=grid.size();
      int n=grid[0].size();
      int ans=pow(2,n-1)*m;

      for(int j=1;j<n;j++){
        int cnt_same=0;
        for(int i=0;i<m;i++){
            if(grid[i][j]==grid[i][0]){
                cnt_same++;
            }
        }
        int cnt_zeros=m-cnt_same;
        int maxi=max(cnt_zeros,cnt_same);
        ans+= (pow(2,n-j-1)*maxi);
      }
      return ans;  
    }
};