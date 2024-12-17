class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        int r=n-1;
        while(l<r){
            while(l+1<n&& nums[l]==nums[l+1]){
                l++;
            }
            while(r-1>=0 && nums[r]==nums[r-1]){
                r--;
            }
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return nums[r];
    }
};