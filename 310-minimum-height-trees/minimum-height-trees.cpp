class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      vector<int>indegree(n);
      if(n==1)return{0};
      unordered_map<int,vector<int>>mp;
      for(auto i: edges){
        int u=i[0];
        int v=i[1];
        indegree[u]++;
        indegree[v]++;
        mp[u].push_back(v);
        mp[v].push_back(u);
      }
      vector<int>ans;
      queue<int>que;
      for( int i=0;i<n;i++){
        if(indegree[i]==1){
            que.push(i);
        }
      } 
      // Topological Sorting Graph \U0001f4ca Problem Solve dBy Kishan Kumar N.
      while(n>2){
        int s=que.size();
        n-=s;
        while(s--){
            int u=que.front();
            que.pop();

            for(auto v:mp[u]){
                indegree[v]--;
                if(indegree[v]==1){
                    que.push(v);
                }
            }
        }
      }
      while(!que.empty()){
        ans.push_back(que.front());
        que.pop();
      }
        return ans;
    }
};