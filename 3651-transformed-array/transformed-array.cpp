class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                int steps=(nums[i])%n;
                int idx=(i+steps)%n;
                ans[i]=nums[idx];
            }
            else if(nums[i]<0){
                int steps=abs(nums[i])%n;
                int idx=(i-steps+n)%n;
                ans[i]=nums[idx];
            }
        }
        return ans;
    }
};