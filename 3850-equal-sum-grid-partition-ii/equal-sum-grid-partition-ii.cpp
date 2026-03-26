class Solution {
public:
   typedef long long ll;
   ll total;

   bool solve(vector<vector<int>>&grid){
    int m=grid.size();
    int n=grid[0].size();

    unordered_set<ll>st;
    ll pref=0;

    for(int i=0;i<m-1;i++){

        for(int j=0;j<n;j++){
            st.insert(grid[i][j]);
            pref+=grid[i][j];
        }
        ll bot=total-pref;
        ll dif=pref-bot;
        

        if(dif==0)return true;
        if(dif==(ll)grid[0][0] || dif==(ll)grid[0][n-1] ) return true;
        if(dif==(ll)grid[i][0]) return true;

        if(i>0 && n>1 && st.count(dif)) return true;
    }

     return false;
   }
     
    bool canPartitionGrid(vector<vector<int>>& grid) {
      int n=grid[0].size();
      int m=grid.size();
     total=0;

     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            total+=grid[i][j];
        }
     }

     if(solve(grid))return true;
      reverse(grid.begin(),grid.end());
      if(solve(grid))return true;

      vector<vector<int>>trans(n,vector<int>(m));

      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            trans[j][i]=grid[i][j];
        }
      }

      if(solve(trans))return true;
      reverse(trans.begin(),trans.end());
      if(solve(trans))return true;

    return false;

    }
};