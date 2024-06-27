class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
      unordered_map<int,int>mp;
      for(auto i:edges){
        int u=i[0];
        int v=i[1];
        mp[u]++;
        mp[v]++;
      }
      for(auto i:mp){
         if(i.second==n)return i.first;
      }
      return -1;  
    }
};