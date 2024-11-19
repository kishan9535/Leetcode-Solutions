class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
       long long ans=0;
       set<int>st;

       int i=0,j=0;
       int n=nums.size();
       long long sum=0;
       while(j<n){
         while(st.count(nums[j])){
            st.erase(nums[i]);
            sum-=nums[i];
            i++;
         }
         sum+=nums[j];
         st.insert(nums[j]);
         
         if(j-i+1==k){
            ans=max(ans,sum);
            sum-=nums[i];
            st.erase(nums[i]);
            i++;
         }
         
         j++;
       }
       return ans; 
    }
};