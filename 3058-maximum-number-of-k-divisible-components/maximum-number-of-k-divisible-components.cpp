class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if (n < 2) return 1;

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<long long> nodeval(values.begin(), values.end());
        int total_components = 0;

     
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

       
        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) { 
                que.push(i);
            }
        }

        
        while (!que.empty()) {
            int node = que.front();
            que.pop();

           
            int add_val = nodeval[node] % k;
            if (add_val == 0) {
                total_components++;
            }

            
            for (auto& neighbor : adj[node]) {
                if (indegree[neighbor] > 0) {
                    indegree[neighbor]--;
                    nodeval[neighbor] = (nodeval[neighbor] + add_val) % k;

                    
                    if (indegree[neighbor] == 1) {
                        que.push(neighbor);
                    }
                }
            }
        }

        return total_components;
    }
};
