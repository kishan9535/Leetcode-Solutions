class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        int l,r;
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=2;i<n;i++){
            l=0;
            r=i-1;
            while(l<r){
                if(nums[l]+nums[r]>nums[i]){
                    ans+=(r-l);
                    r--;
                }
                else
                l++;
            }
        }
        return ans;
    }
};