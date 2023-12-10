class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& A, int target) {
        int n = A.size();
        
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            int a = A[i][0], b = A[i][1], c = A[i][2], m = A[i][3];
            
            long long x = 1;
            while (b--) {
                x *= a;
                x %= 10;
            }
            // printf("x: %d ", x);
            long long y = 1;
            while (c--) {
                y *= x;
                y %= m;
            }
            // printf("y: %d\n", y);
            
            if (y == target*1LL) {
                ans.push_back(i);
            }
        }
        return ans; 
    }
};