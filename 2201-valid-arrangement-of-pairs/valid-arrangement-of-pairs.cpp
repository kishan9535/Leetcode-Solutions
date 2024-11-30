class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        vector<vector<int>>ans;
       unordered_map<int,vector<int>>mp;
       unordered_map<int,int>ind,out;

       for(auto it: pairs){
        int u=it[0];
        int v=it[1];
        mp[u].push_back(v);
        out[u]++;
        ind[v]++;
       }
       int startNode=pairs[0][0];
       for(auto it: mp){
        int node=it.first;
        if(out[node]-ind[node]==1){
            startNode=node;
            break;
        }
       }
       vector<int>e_path;
       stack<int>st;
       st.push(startNode);

       while(!st.empty()){
        int curr=st.top();
        if(!mp[curr].empty()){
            int ngbr=mp[curr].back();
            mp[curr].pop_back();
            st.push(ngbr);
        }
        else{
            e_path.push_back(curr);
            st.pop();
        }
       }
       reverse(e_path.begin(),e_path.end());
       int k=e_path.size();
       for(int i=0;i<k-1;i++){
        int u=e_path[i];
        int v=e_path[i+1];
        ans.push_back({u,v});
       }
       return ans;  
    }
};