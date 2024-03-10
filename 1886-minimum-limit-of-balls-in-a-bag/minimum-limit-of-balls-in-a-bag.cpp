class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
      int l=1;
      int r=*max_element(nums.begin(),nums.end());
      int ans=r;
      int n=nums.size();
     while (l < r) {
            int mid = l + (r - l) / 2;
            int ops = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] > mid) {
                    if (mid != 0){
                    if (nums[i] % mid == 0) {
                        ops += nums[i] / mid - 1;
                    } else {
                        ops += nums[i] / mid;
                    }
                }
                }
            }
            if (ops <= maxOperations) {
                ans = mid;
                r = mid;
            } else {
                l = mid + 1;
            }
        }
      return ans;  
    }
};