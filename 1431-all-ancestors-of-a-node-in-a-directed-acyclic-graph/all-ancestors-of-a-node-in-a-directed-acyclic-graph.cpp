class Solution {
public:
  void dfs(int u, unordered_map<int,vector<int>>&mp, vector<bool>&visited) {
      visited[u] = true;
      for (auto i : mp[u]) {
          if (!visited[i]) {
              dfs(i, mp, visited);
          }
      }
  }

  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
      vector<vector<int>> ans(n);
      unordered_map<int, vector<int>> mp;
      
      for (auto i : edges) {
          int u = i[0];
          int v = i[1];
          mp[v].push_back(u);
      }
      
      for (int i = 0; i < n; i++) {
          vector<bool> visited(n, false);
          dfs(i, mp, visited);
          for (int it = 0; it < n; it++) {
              if (visited[it] && it != i) {
                  ans[i].push_back(it);
              }
          }
      }
      
      return ans; 
  }
};
