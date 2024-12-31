class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();   
        int n = grid[0].size();

       
        for (int i = 0; i < n; i++) {          
            for (int j = 1; j < m; j++) {      
                if (grid[j][i] <= grid[j-1][i]) { 
                    int diff = grid[j-1][i] - grid[j][i] + 1;
                    ans += diff;              
                    grid[j][i] += diff;        
                }
            }
        }

        return ans;
    }
};
