class Solution {
public:
    typedef long long ll;

    int n;
    
   ll memo[1000001][4];
    long long solve(int idx, int t, vector<int>& nums) {

        if (idx == n) {
            if (t == 3) {
                return  0;
            } else {
                return  LLONG_MIN;
            }
        }

        if(memo[idx][t]!=-1) return memo[idx][t];

        ll take = -1e18;
        ll skip = -1e18;
        if (t == 0) {
            skip = solve(idx + 1, 0, nums);
        }
        if (t == 3) {
            take = nums[idx];
        }

        if (idx + 1 < n) {

            if (t == 0 && nums[idx + 1] > nums[idx]) {
                take = max(take, nums[idx] + solve(idx + 1, t + 1, nums));

            }

            else if (t == 1) {
                if (nums[idx + 1] >nums[idx]) {
                    take = max(take, nums[idx] + solve(idx + 1, t, nums));
                } else if(nums[idx+1]<nums[idx]) {
                    take = max(take, nums[idx] + solve(idx + 1, t + 1, nums));
                }
            } else if (t == 2) {
                if (nums[idx + 1] <nums[idx]) {
                    take = max(take, nums[idx] + solve(idx + 1, t, nums));
                } else if(nums[idx+1]>nums[idx]){
                    take = max(take, nums[idx] + solve(idx + 1, t + 1, nums));
                }
            } else if (t == 3 && nums[idx + 1] > nums[idx]) {

                take = max(take, nums[idx] + solve(idx + 1, t, nums));
            }
        }
        return  memo[idx][t]= max(take,skip);
    }

    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        memset(memo,-1,sizeof(memo));
        return solve(0, 0, nums);
    }
};