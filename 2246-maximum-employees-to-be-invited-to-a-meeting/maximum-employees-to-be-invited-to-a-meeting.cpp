class Solution {
public:
     int bfs(int start,unordered_map<int,vector<int>>&adj,vector<bool>&visited){
        queue<pair<int,int>>que;
        int max_cnt=0;
        que.push({start,0});
        while(!que.empty()){
            auto[curnode,dist]=que.front();
            que.pop();

            for(auto it: adj[curnode]){
                if(!visited[it]){
                    visited[it]=true;
                    que.push({it,dist+1});
                    max_cnt=max(max_cnt,dist+1);
                }
            }
             
        }
        return max_cnt;
     }
    int maximumInvitations(vector<int>& favorite) {
      int n=favorite.size();
      unordered_map<int,vector<int>>adj;
      for(int i=0;i<n;i++){
        int u=i;
        int v=favorite[i];
        adj[v].push_back(u);
      }
      int longestcycle_emp_cnt=0;
      int happy_couple_cnt=0;

      vector<bool>vis(n,false);

      for(int i=0;i<n;i++){
        if(!vis[i]){
            unordered_map<int,int>mp;
            int cur_node=i;
            int curnode_cnt=0;

            while(!vis[cur_node]){
                vis[cur_node]=true;
                mp[cur_node]=curnode_cnt;
                int next_node=favorite[cur_node];
                curnode_cnt++;
                if(mp.count(next_node)){
                    int cycle_length=curnode_cnt-mp[next_node];
                    longestcycle_emp_cnt=max(longestcycle_emp_cnt, cycle_length);

                    if(cycle_length==2){
                         vector<bool>vis_nodes(n,false);
                          vis_nodes[cur_node]=vis_nodes[next_node]=true;
                        happy_couple_cnt+=2+bfs(cur_node,adj,vis_nodes)+bfs(next_node,adj,vis_nodes);

                    }
                    break;
                }
                cur_node=next_node;
            }

        }
      }
      return  max(happy_couple_cnt,longestcycle_emp_cnt);
    }
};