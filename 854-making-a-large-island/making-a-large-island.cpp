class Solution {
public:
   vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(vector<vector<int>>& grid,int i,int j,int id){
        int n=grid.size();
         if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) return 0; 
         int ans=1;
         grid[i][j]=id;
         for(auto it:dir){
            int i_=it[0]+i;
            int j_=it[1]+j;
            ans+=dfs(grid,i_,j_,id);

         }
       return ans;
    }
    int largestIsland(vector<vector<int>>& grid) {
      unordered_map<int,int>mp;
      int maxi=0;
      int n=grid.size();
      int unique_id=2;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           if(grid[i][j]==1){
            int size=dfs(grid,i,j,unique_id);
            mp[unique_id]=size;
            unique_id++;
            maxi=max(maxi,size);
           }
        }
      }
      
      for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int ans = 1;
                    unordered_set<int> used_ids; 
                    for (auto it : dir) {
                        int i_ = it[0] + i;
                        int j_ = it[1] + j;
                        if (i_ >= 0 && j_ >= 0 && i_ < n && j_ < n && grid[i_][j_] > 1) {
                            int id = grid[i_][j_];
                            if (used_ids.find(id) == used_ids.end()) {
                                ans += mp[id]; 
                                used_ids.insert(id); 
                            }
                        }
                    }
                    maxi = max(maxi, ans); 
                }
            }
        }
      return maxi; 
    }
};