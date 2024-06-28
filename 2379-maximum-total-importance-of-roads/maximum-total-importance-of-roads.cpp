class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
      vector<int>indegree(n,0);
        for(auto i:roads){
            int u=i[0];
            int v=i[1];
            indegree[v]++;
            indegree[u]++;
        }
        sort(indegree.begin(),indegree.end());
         long long value = 1;
        long long ans   = 0;
        for(int i = 0; i < n; i++) {
            ans += (indegree[i] * value);
            value++;
        }
        return ans;
    }
};