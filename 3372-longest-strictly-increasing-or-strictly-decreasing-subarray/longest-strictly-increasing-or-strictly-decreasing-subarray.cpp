class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int ans = 1; 
        int cnt, prev; 

        for (int i = 0; i < n - 1; i++) {
            cnt = 1;
            prev = nums[i];
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > prev) {
                    cnt++;
                    prev = nums[j];
                } else {
                    break;
                }
            }
            ans = max(ans, cnt);
        }

        for (int i = 0; i < n - 1; i++) {
            cnt = 1;
            prev = nums[i];
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < prev) {
                    cnt++;
                    prev = nums[j];
                } else {
                    break;
                }
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};
