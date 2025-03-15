class Solution {
public:
   bool solve(vector<int>& nums, int k,int mid){
    int n=nums.size();
    int total=0;
    for(int i=0;i<n;i++){
      if(nums[i]<=mid){
        total++;
        i++;
      }
    }
    return total>=k;
   }
    int minCapability(vector<int>& nums, int k) {
      int l=*min_element(nums.begin(),nums.end());
      int r=*max_element(nums.begin(),nums.end());
      int ans=r;
      while(l<=r){
        int mid=l+(r-l)/2;
        if(solve(nums,k,mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
      }
      return ans;  
    }
};