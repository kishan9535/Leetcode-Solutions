class Solution {
public:

  void solve(int ele,set<int>&st){

    st.insert(ele);
    if(st.size()>3){
        st.erase(st.begin());
    }
  }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
       int n=grid[0].size();
       int m=grid.size();

       set<int>st;
       vector<int>ans;

       for(int r=0;r<m;r++){
        for(int c=0;c<n;c++){
            solve(grid[r][c],st);

            for(int k=1; (r-k>=0 && r+k<m && c-k>=0 && c+k<n);k++){
                int sum=0;

                for(int i=1;i<=k;i++){
                    sum+=grid[r-k+i][c+i];
                    sum+=grid[r+i][c+k-i];
                    sum+=grid[r+k-i][c-i];
                    sum+=grid[r-i][c-k+i];
                }
                solve(sum,st);
            }
        }
       }
       ans = vector<int>(st.begin(), st.end());
        reverse(ans.begin(), ans.end());
       return  ans;
    }
};