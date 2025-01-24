class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> revGraph(V);
        vector<int> indegree(V, 0);
        
        for (int u = 0; u < V; u++) {
            for (int v : graph[u]) {
                revGraph[v].push_back(u);  
                indegree[u]++;         
            }
        }
        
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<bool> isSafe(V, false);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            isSafe[node] = true;  
            
            for (int neighbor : revGraph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (isSafe[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};