class Solution {
public:
     int Try_Grid(int coly,int colo,vector<vector<int>>& grid){
         int cnt=0,n=grid.size();
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 if((i<=n/2 &&(i==j || i+j==n-1))||(i>n/2 &&j==n/2)){
                     if(grid[i][j]!=coly)cnt++;
                 }
                 else{
                     if(grid[i][j]!=colo)cnt++;
                 }
             }
         }
         return cnt;
     }
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
     // int ans=0;
     /* for(int i=0;i<=2;i++){
          for(int j=0;j<=2;j++){
              if(i!=j){
                  ans=min(ans,Try_Grid(i,j,grid));
              }
          }
      }*/
      int ans=min({ Try_Grid(1,0,grid),Try_Grid(1,2,grid),Try_Grid(0,1,grid),
      Try_Grid(0,2,grid),Try_Grid(2,0,grid),Try_Grid(2,1,grid)}); 
      return ans; 
    }
};