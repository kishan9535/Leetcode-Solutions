class Solution {
public:

   int Mod=1e9+7;
   typedef long long ll;

   ll power(ll b,ll e){

    if(e==0)return 1;
    ll h=power(b,e/2);
    ll ans=(h*h)%Mod;

    if(e%2==1){
        ans=(ans*b)%Mod;
    }
    return ans;
   }

    int depth(unordered_map<int,vector<int>>&mp,int cur, int par){
        int d=0;

       for(auto &i:mp[cur]){
        if(par==i)continue;
        d=max(d,depth(mp,i,cur)+1);
       }
        return d;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        unordered_map<int,vector<int>>mp;

        for(auto &it : edges){
            int u=it[0];
            int v=it[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        int d=depth(mp,1,-1);

        return power(2,d-1);
        
    }
};