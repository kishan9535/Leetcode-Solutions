typedef vector<int> v;
class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    bool isInside(vector<vector<int>>& moveTime, int i, int j) {
        return i>=0 && j>=0 && i<moveTime.size() && j<moveTime[0].size();
    }
    int bfs(vector<vector<int>>& moveTime, int i, int j, int currTime, vector<vector<bool>>&vis) {
        priority_queue<v, vector<v>, greater<v>>q;
        q.push({currTime, i, j, 0});
        int row = moveTime.size(), col = moveTime[0].size();
        vector<vector<int>>dis(row, vector<int>(col, INT_MAX));
        dis[0][0] = 0;
        while (!q.empty()) {
            v curr = q.top();
            q.pop();
            if (vis[curr[1]][curr[2]]) {
                continue;
            }
            vis[curr[1]][curr[2]] = true;
            for (int k=0;k<4;k++) {
                int x = dx[k]+curr[1], y = dy[k]+curr[2];
                if (isInside(moveTime, x, y)) {
                    int time = curr[3]+1;
                    if (dis[x][y] > time+max(moveTime[x][y], curr[0])) {
                        dis[x][y] = time+max(moveTime[x][y], curr[0]);
                        q.push({dis[x][y], x, y, curr[3]^1});
                    }
                }
            }
        }
        return dis[row-1][col-1];
    }
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int r = moveTime.size(), c = moveTime[0].size();
        vector<vector<bool>>vis(r, vector<bool>(c, false));
        return bfs(moveTime, 0, 0, 0, vis);
    }
};