class Solution {
public:
    const int mod = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        r = r - l + 1;
        vector<long long> dp(r, 0);
        iota(dp.begin(), dp.end(), 0);
        for (int i = 2; i < n; ++i) {
            long long pre = 0, cur = 0;
            if (i % 2 == 0) {
                for (int j = r - 1; j >= 0; --j) {
                    cur = (pre + dp[j]) % mod;
                    dp[j] = pre;
                    pre = cur;
                }
            } else {
                for (int j = 0; j < r; ++j) {
                    cur = (pre + dp[j]) % mod;
                    dp[j] = pre;
                    pre = cur;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < r; ++i) {
            ans = (ans + dp[i]) % mod;
        }
        return ans * 2 % mod;
    }
};