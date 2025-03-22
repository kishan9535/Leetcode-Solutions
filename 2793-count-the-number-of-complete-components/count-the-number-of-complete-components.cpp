class Solution {
public:
  void dfs(unordered_map<int,vector<int>>&mp,vector<bool>&vis,int &e,int &v,int node){
     vis[node]=true;
     e+=mp[node].size();
     v++;

     for(auto it: mp[node]){
        if(!vis[it]){
            dfs(mp,vis,e,v,it);
        }
     }
  }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
       int ans=0;
       unordered_map<int,vector<int>>mp;
       for(auto it: edges){
        int u= it[0];
        int v=it[1];
        mp[u].push_back(v);
        mp[v].push_back(u);
       }
       vector<bool>vis(n,false);
       for(int i=0;i<n;i++){
          if(vis[i]==true)continue;
          int e=0,v=0;
          dfs(mp,vis,e,v,i);
          if(v*(v-1)==e)ans++;


       }
       return ans; 
    }
};