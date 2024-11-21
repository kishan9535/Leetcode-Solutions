class Solution {
public:
 
       void markgrid(int gi,int gj,vector<vector<int>>&grid){
        for(int i=gi-1;i>=0;i--){
           if(grid[i][gj]==2 || grid[i][gj]==3){
            break;
           }
           grid[i][gj]=1;
        }
        for(int i=gi+1;i<grid.size();i++){
            if(grid[i][gj]==2 || grid[i][gj]==3){
            break;
           }
           grid[i][gj]=1;
        }
        for(int j=gj-1;j>=0;j--){
             if(grid[gi][j]==2 || grid[gi][j]==3){
            break;
           }
           grid[gi][j]=1;
        }
        for(int j=gj+1;j<grid[0].size();j++){
             if(grid[gi][j]==2 || grid[gi][j]==3){
            break;
           }
           grid[gi][j]=1;
        }

       }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int cnt=0;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(auto it: guards){
            int i=it[0];
            int j=it[1];
            grid[i][j]=2;
        }
        for(auto it:walls){
            int i=it[0];
            int j=it[1];
            grid[i][j]=3;
        }
        for(auto it: guards){
            int i=it[0];
            int j=it[1];
            markgrid(i,j,grid);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)cnt++;
            }
        }
        return cnt;
    }
};