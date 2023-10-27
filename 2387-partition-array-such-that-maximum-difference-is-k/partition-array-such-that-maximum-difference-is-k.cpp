class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int l=0;
        int ans=1;
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=1;i<nums.size();i++){
            if(nums[l]-nums[i]>k){
                ans++;
                l=i;
            }
        }
        return ans;
    }
};