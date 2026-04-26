class Solution {
public:
  
  int m,n;
  vector<vector<int>>dir{{0,1},{0,-1},{1,0},{-1,0}};

  bool IsCycle(vector<vector<char>>&grid,vector<vector<bool>>&vis, int i,int j,int pi,int pj){
    
    if(i<0 ||i>m || j<0||j>n)return false;

    if(vis[i][j])return true;

    vis[i][j]=true;

    for(auto &it:dir){
        int ni=i+it[0];
        int nj=j+it[1];

        if(ni>=0 &&ni<m &&nj>=0 &&nj<n && grid[i][j]==grid[ni][nj]){

            if(ni==pi && nj==pj)continue;

            if(IsCycle(grid,vis,ni,nj,i,j)){
                return true;
            }
        }
    }
    return false;

  }

    bool containsCycle(vector<vector<char>>& grid) {
      n=grid[0].size();
     m=grid.size();

     vector<vector<bool>>vis(m,vector<bool>(n,false));

     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && IsCycle(grid,vis,i,j,-1,-1)){
                return true;
            }
        }
     }
     return false;

    }
};