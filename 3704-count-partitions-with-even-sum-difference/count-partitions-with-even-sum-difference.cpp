class Solution {
public:
    int countPartitions(vector<int>& nums) {
      int pref_sum=accumulate(nums.begin(),nums.end(),0);
      int sum=0,cnt=0;
      int n=nums.size();
      for(int i=0;i<n-1;i++){
        sum+=nums[i];
        if(abs(sum-(pref_sum-sum))%2==0)cnt++;
      }
      return cnt;  
    }
};