class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
      int n=nums.size();
      int max_balanced=1;
      sort(nums.begin(),nums.end());
      int i=0,j=0;

      while(j<n){
        int mini=nums[i];
        int maxi=nums[j];

        while(maxi> (long long)mini*k && i<j){
            i++;
            mini=nums[i];
        }
        
         max_balanced=max(max_balanced,(j-i+1));
         maxi=nums[j];
         j++;
      }
     return n-max_balanced;
    }
};