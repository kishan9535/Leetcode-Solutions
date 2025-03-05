class Solution {
public:
    long long coloredCells(int n) {
      long long ans=1;
      int t=1;
      while(t<=n){
        ans+=(4*(t-1));
        t++;
      }  
      return ans;
    }
};