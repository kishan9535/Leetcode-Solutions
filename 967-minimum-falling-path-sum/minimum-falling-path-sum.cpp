class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m , vector<int>(n , 0));
        for(int j = 0 ;j<n;j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i =1;i<m;i++){
            for(int j =0;j<n;j++){

                int up  = matrix[i][j]+  dp[i-1][j];
                int upl = matrix[i][j];
                if(j-1>=0) upl += dp[i-1][j-1];
                else upl += 1e9;

                int upr = matrix[i][j];
                if(j+1<n) upr += dp[i-1][j+1];
                else upr += 1e9;

                dp[i][j] = min(up,min(upl , upr));
            }
        }

        int mini = INT_MAX;
        for(int j =0;j<n;j++){
            mini = min(mini , dp[n-1][j]);
        }
        return mini;

    }
};