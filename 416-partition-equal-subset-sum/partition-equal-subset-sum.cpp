class Solution {
public:
int n;
    bool solve(int idx,vector<int>& nums,int target,vector<vector<int>>&t){
        if(target==0)return true;
        if(idx>=n)return false;
        if(t[idx+1][target]!=-1) return t[idx+1][target];
        bool take=false;
        if(nums[idx]<=target){
            take=solve(idx+1,nums,target-nums[idx],t);
        }
        bool skip=solve(idx+1,nums,target,t);
        return t[idx+1][target]= (take||skip);
         
    }
    bool canPartition(vector<int>& nums) {
     int sum=0;
     n=nums.size();
     for(auto i:nums){
         sum+=i;
     }
     if(sum%2!=0)return false;
     vector<vector<int>>t(n+1,vector<int>(sum+1,-1));
     return solve(0,nums,sum/2,t);   
    }
};