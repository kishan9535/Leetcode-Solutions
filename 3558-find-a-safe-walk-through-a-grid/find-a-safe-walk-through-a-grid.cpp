class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health){

        int m=grid.size();
        int n=grid[0].size();
        deque<pair<int,int>>dq;
        vector<vector<int>>ans(m,vector<int>(n,INT_MAX));
        ans[0][0]=grid[0][0];
        dq.push_front({0,0});

        vector<vector<int>>dir{{0,1},{1,0},{0,-1},{-1,0}};

        while(!dq.empty()){
            auto it=dq.front();
            dq.pop_front();
            int i=it.first;
            int j=it.second;

            for(auto d:dir){
                int ni=d[0]+i;
                int nj=d[1]+j;

                if(ni<0 ||ni>=m ||nj<0||nj>=n)continue;

                if(ans[ni][nj]>grid[ni][nj]+ans[i][j]){
                    ans[ni][nj]=grid[ni][nj]+ans[i][j];

                    if(grid[ni][nj]==0){
                        dq.push_front({ni,nj});
                    }
                    else{
                        dq.push_back({ni,nj});
                    }
                }
            }

          
        }

        return (health-(ans[m-1][n-1]))>=1;

    }
};