class Solution {
public:
  typedef long long ll;
  int n;

  ll t[2][101][101];

  long long solve(int prevheight,int col, bool prev ,vector<vector<int>>&grid,vector<vector<ll>>&pref){

    if(col==n)return 0;

    if(t[prev][prevheight][col]!=-1){
        return t[prev][prevheight][col];
    }
     
     ll ans=0;
     for(int h=0;h<=n;h++){
       ll prevh=0;
       ll curh=0;


       if(!prev && col-1>=0 && h>prevheight){
        prevh+=pref[h][col]-pref[prevheight][col];
       }

       if(prevheight>h){
        curh+=pref[prevheight][col+1]-pref[h][col+1];
       }

       ll taken=prevh+curh+solve(h,col+1,true,grid,pref);
       ll skip=prevh+solve(h,col+1,false,grid,pref);

       ans=max({ans,taken,skip});
     }
     return t[prev][prevheight][col]= ans;
  }

    long long maximumScore(vector<vector<int>>& grid) {
       n=grid.size();
       vector<vector<ll>>pref(n+1,vector<ll>(n+1,0));

       for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            pref[j][i]=pref[j-1][i]+grid[j-1][i-1];
        }

       }
        
        memset(t,-1,sizeof(t));

       return solve(0,0,false,grid,pref); 
    }
};