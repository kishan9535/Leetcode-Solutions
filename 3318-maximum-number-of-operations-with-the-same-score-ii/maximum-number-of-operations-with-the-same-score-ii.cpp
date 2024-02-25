class Solution {
public:
int t[2001][2001];
    int solve(int i,int j, int target,vector<int>&nums){
        if(i>=j)return 0;
        int ans=0;
        if(t[i][j]!=-1)return t[i][j];
        if(nums[i]+nums[j]==target)
        ans=max(ans,1+solve(i+1,j-1,target,nums));
        if(nums[i]+nums[i+1]==target)
        ans=max(ans,1+solve(i+2,j,target,nums));
        if(nums[j]+nums[j-1]==target)
        ans=max(ans,1+solve(i,j-2,target,nums));
        return t[i][j]= ans;
    }
    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
       int op1=solve(0,n-1,nums[0]+nums[n-1],nums); 
               memset(t,-1,sizeof(t));

       int op2=solve(0,n-1,nums[0]+nums[1],nums);
               memset(t,-1,sizeof(t));

       int op3=solve(0,n-1,nums[n-2]+nums[n-1],nums);
       return max({op1,op2,op3});
    }
};