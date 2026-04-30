class Solution {
public:
    int n,m;


   int solve(int i,int j,int cost,vector<vector<int>>&grid,int k,vector<vector<vector<int>>>&t){

        if(i>=m || j>=n) return INT_MIN;

        int new_cost=cost+(grid[i][j]>0);

        if(new_cost>k)return INT_MIN;


        if(i==m-1 && j==n-1)return grid[i][j];

        if(t[i][j][cost]!=-1)return t[i][j][cost];

        int down=solve(i+1,j,new_cost,grid,k,t);
        int right=solve(i,j+1,new_cost,grid,k,t);

        int maxi=max(down,right);

        if(maxi==INT_MIN)return t[i][j][cost]= INT_MIN;

        return t[i][j][cost]= maxi+grid[i][j];

    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n=grid[0].size();
        m=grid.size();

            vector<vector<vector<int>>>t(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
      
       int ans=solve(0,0,0,grid,k,t);

       return ans==INT_MIN?-1:ans;
    }
};