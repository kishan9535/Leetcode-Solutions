class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
     int n=grid.size();
     int m=grid[0].size();
     vector<int>row_cnt(n,0);
     vector<int>col_cnt(m,0);

     for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){ // changed from n to m
            if(grid[i][j]==1)cnt++;
        }
        row_cnt[i]=cnt;
     }

     for(int j=0;j<m;j++){
        int cnt=0;
        for(int i=0;i<n;i++){ // changed from j to i
            if(grid[i][j]==1)cnt++; // changed from grid[j][i] to grid[i][j]
        }
        col_cnt[j]=cnt;
     }
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans+=(row_cnt[i]-1) *(col_cnt[j]-1);
                }
            }
        }
     
     return ans;    
    }
};
