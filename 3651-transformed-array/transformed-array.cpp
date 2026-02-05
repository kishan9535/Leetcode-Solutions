class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
       vector<int>ans;

       for(int i=0;i<n;i++){
          if(nums[i]>0){
           int step= nums[i];
           int idx=(step+i)%n;
           ans.push_back(nums[idx]); 
          }
          
          else{
            int step=abs(nums[i])%n;
            int idx=(i-step+n)%n;
            
            ans.push_back(nums[idx]);
          }
       }

   return ans;
    }
};