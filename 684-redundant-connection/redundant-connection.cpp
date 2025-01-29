class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>&adj,int s,int e,vector<bool>&vis){
        vis[s]=true;
        if(s==e)return true;
          bool ans=false;
        for(auto it: adj[s]){
            if(!vis[it]){
                ans|=dfs(adj,it,e,vis);
            }
        }
        return ans;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int n=edges.size();
      vector<bool>main_vis(n,false);
      unordered_map<int,vector<int>>adj;
      for(auto it: edges){
        int u=it[0];
        int v=it[1];
         vector<bool>vis(n,0);
        if(dfs(adj,u,v,vis)){
            return {u,v};
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      return {};  
    }
};