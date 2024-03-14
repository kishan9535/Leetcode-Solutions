class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
      int n=nums.size();
       int continous_cnt=0;
      long long ans=0;
      
      for(int i=0;i<n;i++){
        if(nums[i]==0){
            continous_cnt++;
        }
        else{
            continous_cnt=0;
        }
        ans=ans+continous_cnt;
      }
      return ans;  
    }
};