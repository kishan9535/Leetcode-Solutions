class Solution {
public:
   
   int Mod=1e9+7;
   int t[201][201][201];

   int solve(int idx,int gcd1,int gcd2,vector<int>&nums){

      int n=nums.size();

      if(idx>=n){
        if(gcd1!=0 && gcd2!=0){
            if(gcd1==gcd2)return 1;
        }
        return 0;
       
      }

      if(t[idx][gcd1][gcd2]!=-1)return t[idx][gcd1][gcd2];

      int skip=solve(idx+1,gcd1,gcd2,nums);
      int g1=solve(idx+1,__gcd(gcd1,nums[idx]),gcd2,nums);
      int g2=solve(idx+1,gcd1,__gcd(nums[idx],gcd2),nums);

      return t[idx][gcd1][gcd2]= (0LL+skip+g1+g2)%Mod;
   }

    int subsequencePairCount(vector<int>& nums) {

        memset(t,-1,sizeof(t));

     return solve(0,0,0,nums);   
    }
};