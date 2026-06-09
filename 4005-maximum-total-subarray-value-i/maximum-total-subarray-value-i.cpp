class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());

        long long ans=(maxi-mini);

        return 1L*ans*k;
        
    }
};