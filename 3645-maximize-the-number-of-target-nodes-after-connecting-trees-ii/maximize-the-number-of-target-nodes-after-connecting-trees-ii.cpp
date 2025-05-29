class Solution {

    void dfs(int curr, unordered_map<int, vector<int>>& adj, int parent,
             int& evenCnt, int& oddCnt, vector<int>& parity, int depth) {
        if (depth & 1) {
            oddCnt++;
            parity[curr] = 1;
        } else {
            evenCnt++;
            parity[curr] = 0;
        }

        for (auto& n : adj[curr]) {
            if (n != parent)
                dfs(n, adj, curr, evenCnt, oddCnt, parity, depth + 1);
        }
    }

    vector<int> findCnt(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int evenCnt = 0, oddCnt = 0;
        vector<int> parity(n, 0);
        dfs(0, adj, -1, evenCnt, oddCnt, parity, 0);

        vector<int> res(n);
        for (int i = 0; i < n; i++) {

            res[i] = (parity[i] == 0 ? evenCnt : oddCnt);
        }
        return res;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int N = edges1.size() + 1;
        vector<int> res1 = findCnt(edges1);
        vector<int> res2 = findCnt(edges2);
        int maxCnt = *max_element(res2.begin(), res2.end());

        for (int i = 0; i < res1.size(); i++) {
            res1[i] += maxCnt;
        }
        return res1;
    }
};