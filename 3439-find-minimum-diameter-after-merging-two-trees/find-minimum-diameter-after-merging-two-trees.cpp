class Solution {
public:
    int find_last(unordered_map<int,vector<int>>&mp,int node){
        int last_ele=node;
        queue<int>que;
        que.push(node);
        int level=0;
        set<int>st;
        st.insert(node);
        while(!que.empty()){
            int n=que.size();
            while(n--){
                int node=que.front();
                que.pop();
                
                for(auto it:mp[node]){
                    if(st.find(it)==st.end()){
                        que.push(it);
                        st.insert(it);
                        last_ele=it;
                    }
                }

            }
            level++;
        }
        return last_ele;
    }

    int find_diamater(unordered_map<int,vector<int>>&mp){
        int a=find_last(mp,0);
        queue<int>que;
        que.push(a);
        int level=-1;
        set<int>st;
        st.insert(a);
        while(!que.empty()){
            int n=que.size();
            while(n--){
                int node=que.front();
                que.pop();
                
                for(auto it:mp[node]){
                    if(st.find(it)==st.end()){
                        que.push(it);
                        st.insert(it);
                    }
                }

            }
            level++;
        }
       return level;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
      unordered_map<int,vector<int>>mp1,mp2;
      for(auto it: edges1){
        int u=it[0];
        int v=it[1];
        mp1[u].push_back(v);
        mp1[v].push_back(u);
      }
      for(auto it: edges2){
        int u=it[0];
        int v=it[1];
        mp2[u].push_back(v);
        mp2[v].push_back(u);
      }
      int d1=find_diamater(mp1);
      int d2=find_diamater(mp2);

      int added_diameter= (d1+1)/2 +(d2+1)/2 +1;

      return max({d1,d2,added_diameter});    
    }
};