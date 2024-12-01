class Solution {
public:
    int dfs(int node,unordered_map<int,vector<int>>&mp,int k,vector<bool>&vis){
      if(k==0)return 0;
      vis[node]=true;
      int cnt=0;
      for(auto it: mp[node]){
          if(!vis[it]){
            cnt++;
            cnt+=dfs(it,mp,k-1,vis);
          }
      }
      return cnt;  
    }
     int bfs(int node,unordered_map<int,vector<int>>&mp,int k,vector<bool>&vis){
        int cnt = 0; 
    queue<int> que;
    que.push(node);
    vis[node] = true;

    while (!que.empty() && k >= 0) {
        int size = que.size(); 
        for (int i = 0; i < size; i++) {
            int curr = que.front();
            que.pop();
            cnt++; 

            for (auto neighbor : mp[curr]) {
                if (!vis[neighbor]) {
                    que.push(neighbor);
                    vis[neighbor] = true; 
                }
            }
        }
        k--; 
    }

    return cnt;
     }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
       int n1=edges1.size()+1;
       int m1=edges2.size()+1;
       //cout<<n1;
       vector<int>ans(n1,0);
       unordered_map<int,vector<int>>mp;
       unordered_map<int,vector<int>>mp1;

       for(auto edge : edges1) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
        for(auto edge : edges2) {
            mp1[edge[0]].push_back(edge[1]);
            mp1[edge[1]].push_back(edge[0]);
        }
        int golden_cnt=0;
        for(int i=0;i<m1;i++){
            vector<bool>vis(m1,false);
            int cnt=bfs(i,mp1,k-1,vis);
            if(cnt>golden_cnt){
                golden_cnt=cnt;
            }
        }
       
       for(int i=0;i<n1;i++){
        vector<bool>vis(n1,false);
         int cnt=dfs(i,mp,k,vis);
         ans[i]=cnt+1+golden_cnt;
       }
        
       return ans;  
    }
};