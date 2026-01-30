class Solution {
public:
   typedef long long ll;
   typedef pair<ll,string>P;
   ll BIG=1e10;
   unordered_map<string,vector<pair<string,ll>>>mp;
    vector<ll>memo;
    string sourcestr;
    string targetstr;
    set<int>val_length;

      ll dijkstra(string start, string end){
        priority_queue<P,vector<P>,greater<P>>pq;
        unordered_map<string,ll>result;
        result[start]=0;
        pq.push({0,start});

        while(!pq.empty()){
            ll curcost=pq.top().first;
            string node=pq.top().second;
            pq.pop();

            if(node==end){
                break;
            }

            for(auto &it: mp[node]){
                string adjnode=it.first;
                ll edgecost=it.second;

                if( !result.count(adjnode) || curcost+edgecost< result[adjnode]){
                    result[adjnode]=curcost+edgecost;
                    pq.push({curcost+edgecost,adjnode});
                }
            }
        }

        ll finalans=result.count(end)? result[end]:BIG;

        return finalans;
      }


    long long solve(int idx){
        if(idx>=sourcestr.size()){
            return 0;
        }

        if(memo[idx]!=-1){
            return memo[idx];
        }

        ll mincost=BIG;

        if(sourcestr[idx]==targetstr[idx]){
            mincost=solve(idx+1);
        }

        for(auto &it: val_length){
            if(idx+it>sourcestr.length()){
                break;
            }
            string srcsub=sourcestr.substr(idx,it);
            string tarsub=targetstr.substr(idx,it);

            if(!mp.count(srcsub)){
               continue;
            }

            ll mincostpath=dijkstra(srcsub,tarsub);

            if(mincostpath==BIG){
                continue;
            }
            mincost=min(mincost,mincostpath+solve(idx+it));

        }
        return memo[idx]=mincost; 
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {

       sourcestr=source;
       targetstr=target;

       memo.assign(10001,-1);

       for(int i=0;i<original.size();i++){
        mp[original[i]].push_back({changed[i],cost[i]});
        int len=original[i].length();
        val_length.insert(len);
       }
       ll ans=solve(0);

       return ans==BIG ?-1:ans; 
    }
};