class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
       int n = prices.size();
        int i = 0, j = 0;
        long long cnt = 0;

        while (j < n) {
            if (i==j||prices[j-1]-prices[j]==1) {
                cnt += (j - i + 1);

                j++;
            } else {
                i = j;
            }
        }

        return cnt;     
    }
};