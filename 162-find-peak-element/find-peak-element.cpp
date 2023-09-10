class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int low=0;
        int high=n-1;
        while(low<high){
            int m=low+(high-low)/2;
            if(nums[m]>nums[m+1]){
                high=m;
            }
            else{
                low=m+1;
            }
        }
        return low; 
    }
};