class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
      int s=nums.size();
      int patches_used=0;
      long long max_sum=0;
      int i=0;
      while(max_sum<n){
        if( i<s && nums[i]<=max_sum+1){
            max_sum+=nums[i];
            i++;
        }
        else{
            max_sum+=(max_sum+1);
            patches_used++;
        }
      }
      return patches_used;  
    }
};