class Solution {
public:
   int Mod=1e9+7;
   int t[201][201][2];

    int solve(int zero, int one, bool flag ,int limit){
      if(zero==0 && one==0)return 1;

      int res=0;

      if(t[zero][one][flag]!=-1)return t[zero][one][flag];

      if(flag){
        for(int l=1;l<=min(limit,one);l++){
         res=(res+solve(zero,one-l,!flag,limit))%Mod;
        }
      }
      else{
        for(int l=1;l<=min(limit,zero);l++){
            res=(res+solve(zero-l,one,!flag,limit))%Mod;
        }
      }
      return t[zero][one][flag]= res;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
      memset(t,-1,sizeof(t));
      int ans=solve(zero,one,true,limit)%Mod;
      ans= (ans+solve(zero,one,false,limit))%Mod;

      return ans;  
    }
};