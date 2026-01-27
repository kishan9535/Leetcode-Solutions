class Solution {
public:
   typedef pair<int,int> P;

    int minCost(int n, vector<vector<int>>& edges) {
       unordered_map<int,vector<P>>mp;

       for(auto it: edges){
        int u=it[0];
        int v=it[1];
        int w=it[2];

        mp[u].push_back({v,w});
        mp[v].push_back({u,2*w});
       }

       priority_queue<P,vector<P>, greater<P>> pq;
       vector<int>ans(n,INT_MAX);
       ans[0]=0;

       pq.push({0,0});

       while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;

        pq.pop();

        if(node==n-1){
            return ans[node];
        }

        for(auto it: mp[node]){
            int adjnode=it.first;
            int dist= it.second;

            if(d+dist<ans[adjnode]){
                ans[adjnode]=d+dist;
                pq.push({d+dist,adjnode});
            }
        }
       }
       return -1;    
    }
};