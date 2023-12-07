class Solution {
public:
int n;
long long t[100005][2];
    long long solve(int idx,int flag,vector<int>& nums,int x){
        if(idx>=n)return 0;
        if(t[idx][flag]!=-1) return t[idx][flag];
        long long take=0;
        long long skip=0;
        skip=solve(idx+1,flag,nums,x);
        if(nums[idx]%2==flag){
            take=nums[idx]+solve(idx+1,flag,nums,x);
        }
        else{
            take=nums[idx]-x +solve(idx+1,nums[idx]%2,nums,x);
        }
        return  t[idx][flag]=max(take,skip);
    }
    long long maxScore(vector<int>& nums, int x) {
      n=nums.size();
      memset(t,-1,sizeof(t));
      return nums[0]+ solve(1,nums[0]%2,nums,x);  
    }
};