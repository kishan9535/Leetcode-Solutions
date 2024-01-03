class Solution {
public:
     int n;
     int t[2500][2500];
     int solve(int idx, int prev,vector<int>& nums){
         if(idx==n)return 0;
         if(t[idx][prev+1]!=-1)return t[idx][prev+1];
         int take=0,skip=0;
         if(prev==-1 ||nums[idx]>nums[prev]){
             take=1+solve(idx+1,idx,nums);
         }
         skip=solve(idx+1,prev,nums);
         return t[idx][prev+1]=max(take,skip);
     }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,-1,nums);
    }
};