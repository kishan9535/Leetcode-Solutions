class Solution {
public:
    int maxScore(vector<int>& nums) {
       sort(nums.rbegin(),nums.rend());
       vector<long long>ans(nums.size());
       ans[0]=nums[0]; 
       long cnt=1;
       if(nums[0]<=0)return 0;
       for(int i=1;i<nums.size();i++){
           ans[i]=(ans[i-1]+nums[i]);
           if(ans[i]>0)cnt++;
       }
       return cnt;
    }
};