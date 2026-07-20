class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m=grid.size();
        int n=grid[0].size();
        int s=m*n;
        k=k%s;
        if(k==0)return grid;


        auto reverse=[&](int i, int j){
            while(i<j){
                swap(grid[i/n][i%n],grid[j/n][j%n]);
                i++;
                j--;
            }
        };



        reverse(0,s-1);
        reverse(0,k-1);
        reverse(k,s-1);

        return grid;
        
    }
};