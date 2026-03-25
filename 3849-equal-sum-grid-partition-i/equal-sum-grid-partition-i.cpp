class Solution {
public:
  typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {

     ll total=0;
     int n=grid[0].size();
     int m=grid.size();

     vector<ll>row(m,0);
     vector<ll>col(n,0);

     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          row[i]+=grid[i][j];
          col[j]+=grid[i][j];
          total+=grid[i][j];
        }
     }

     if(total%2!=0)return false;

     ll sum=0;

     for(int i=0;i<m;i++){
        sum+=row[i];
        ll rem=total-sum;
        if(sum==rem)return true;
     }
     sum=0;
     for(int j=0;j<n;j++){
       sum+=col[j];
       ll rem=total-sum;
       if(sum==rem)return true;
     }   
      
      return false;
    }
};