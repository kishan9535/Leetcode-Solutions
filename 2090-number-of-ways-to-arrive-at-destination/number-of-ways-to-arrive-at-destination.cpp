class Solution {
public:
int M=1e9+7;
typedef pair<long long,long long>p;
    int countPaths(int n, vector<vector<int>>& roads) {
       unordered_map<int,vector<pair<int,int>>>adj;
       for(auto& road:roads){
        int u=road[0];
        int v=road[1];
        int time=road[2];
        adj[u].push_back({v,time});
        adj[v].push_back({u,time});
        } 
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<long long>result(n,LLONG_MAX);
        vector<int>countPath(n,0);
        result[0]=0;
        countPath[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            long long currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            for(auto& vec:adj[currNode]){
                int ngbr=vec.first;
                int roadTime=vec.second;
                if((long long)currTime+roadTime<result[ngbr]){
                    result[ngbr]=(long long)currTime+roadTime;
                    pq.push({result[ngbr],ngbr});
                    countPath[ngbr]=countPath[currNode];
                }else if((long long)currTime+roadTime==result[ngbr]){
                    countPath[ngbr]=(countPath[ngbr]+countPath[currNode])%M;
                }
            }
        }
        return countPath[n-1];
    }
};