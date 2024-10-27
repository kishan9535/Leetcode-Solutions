class Solution {
public:
    int n,m;
    int t[3001][3001];
    int solve(int i,int j,vector<vector<int>>& matrix){
       if(i>=m || j>=n|| matrix[i][j]==0)return 0;
        
        if(t[i][j]!=-1)return t[i][j];
       int left=solve(i+1,j,matrix);
       int diag=solve(i+1,j+1,matrix);
       int right=solve(i,j+1,matrix);

       return t[i][j]= 1+min({left,diag,right});

    }
    int countSquares(vector<vector<int>>& matrix) {
       m = matrix.size();      
       n = matrix[0].size();  
       memset(t,-1,sizeof(t)); 

       int ans=0;

       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1){
                ans+=solve(i,j,matrix);
            }
        }
       }
        return ans;
       } 
    
};