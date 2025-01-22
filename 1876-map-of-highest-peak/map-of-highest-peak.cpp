class Solution {
public:
   bool isValid(int i,int j,vector<vector<int>>& ans){
       int m = ans.size();
       int n = ans[0].size();
       if (i < 0 || i >= m || j < 0 || j >= n || ans[i][j] != -1) 
           return false;
       return true;
   }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
       int n=isWater[0].size();
       int m=isWater.size();
       vector<vector<int>>ans(m,vector<int>(n,-1));
       queue<pair<int,int>>que;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(isWater[i][j]==1){
                ans[i][j]=0;
                que.push({i,j});
            }
        }
       }
       vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
       while(!que.empty()){
         auto i=que.front();
         que.pop();
         for(auto it: dir){
            int i_=i.first+it[0];
            int j_=i.second+it[1];
            if(isValid(i_,j_,ans)){
                ans[i_][j_]=ans[i.first][i.second]+1;
                que.push({i_,j_});
            }
         }
       }
       return ans; 
    }
};