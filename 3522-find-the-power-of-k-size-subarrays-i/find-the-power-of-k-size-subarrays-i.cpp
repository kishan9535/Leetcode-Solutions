class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        int s=(n-k+1);
       vector<int>ans(s,-1);
       int i=0,j=0;
       int cnt=1;
       for(j=1;j<k;j++){
         if(nums[j]==nums[j-1]+1)cnt++;
         else cnt=1;
       }
       if(cnt == k) {
            ans[0] = nums[k-1];
        }

         i = 1;
         j = k;

       while(j<n){
        
        if(nums[j-1]+1==nums[j]){
            cnt++;
        }
        else{
            cnt=1;
        }
         if(cnt>=k){
            ans[i]=nums[j];
         }
         i++;
         j++;
       }
       return ans;
    }
};