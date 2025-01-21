class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
      long long ans= LONG_MAX;
      int n=grid[0].size();
      if(n<2)return 0;
      long long pref_sum=accumulate(grid[0].begin(),grid[0].end(),0LL);
      long long bottom_sum=0;

      for(int i=0;i<n;i++){
        pref_sum-=grid[0][i];
        ans=min(ans,max(pref_sum,bottom_sum));
        bottom_sum+=grid[1][i];
      }
      return ans;
    }
};