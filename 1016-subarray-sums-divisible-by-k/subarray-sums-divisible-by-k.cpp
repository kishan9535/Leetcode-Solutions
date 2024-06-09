class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       int ans=0;
       unordered_map<int,int>mp;
       int sum=0;
       mp[0]=1;
       int n=nums.size();
       int rem;
       for(int i=0;i<n;i++){
          sum+=nums[i];
          rem=sum%k;

          if(rem<0){
            rem+=k;
          }
         if(mp.find(rem)!=mp.end()){
            ans+=mp[rem];
         }
         mp[rem]++;
       }
       return ans;
    }
    
};