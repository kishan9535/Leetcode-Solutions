class Solution {
public:
   bool dfs(unordered_map<int,vector<int>>&mp,int source, int destination,vector<int>&vis){
          if(source==destination)return true;
          vis[source]=-1;
          for(auto i:mp[source]){
            if(vis[i]==1){
                if(dfs(mp,i,destination,vis)) return true;
            }
          }
     return false;
   }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      unordered_map<int,vector<int>>mp;
      vector<int>vis(n,1);
      for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        mp[u].push_back(v);
        mp[v].push_back(u);
      }
     queue<int>qu;
     qu.push(source);
     while(!qu.empty()){
        int node=qu.front();
        qu.pop();
        if(node==destination)return true;

        for(auto i:mp[node]){
            if(vis[i]==1){
                qu.push(i);
                vis[i]=-1;
            }
        }
     }
     return false;
    }
};
