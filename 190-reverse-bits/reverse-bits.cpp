class Solution {
public:
    int reverseBits(int n) {
      if(n==0)return n;

      int ans=0;

      for(int i=0;i<=31;i++){
        ans<<=1;

        ans= (ans|(n&1));
        n>>=1;
      }
      return ans;  
    }
};