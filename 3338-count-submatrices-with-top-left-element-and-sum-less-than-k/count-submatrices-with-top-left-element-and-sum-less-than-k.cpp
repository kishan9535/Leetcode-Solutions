class Solution {
public:
    int countSubmatrices(vector<vector<int>>& nums, int k) {
      int ans=0;
      int n=nums.size(),m=nums[0].size();
      vector<vector<int>>dp(n,vector<int>(m,0));

      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(i==0 && j==0){
                  dp[i][j]=nums[i][j];
              }
              else if( i==0){
                  dp[i][j]+=dp[i][j-1]+nums[i][j];
              }
              else if(j==0){
                  dp[i][j]+=dp[i-1][j]+nums[i][j];
              }
              else{
                  dp[i][j]+=dp[i-1][j]+dp[i][j-1]+nums[i][j]-dp[i-1][j-1];
              }
              if(dp[i][j]<=k)ans++;
          }
      }
      return ans;  
    }
};