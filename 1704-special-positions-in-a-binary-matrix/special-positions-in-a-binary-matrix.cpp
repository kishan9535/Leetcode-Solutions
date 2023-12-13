class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
     int ans=0;
     int m=mat.size();
     int n=mat[0].size();
     vector<int>col1(m,0);
     vector<int>row1(n,0);
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
              col1[i]++;
              row1[j]++;  
            }
        }
     }
      for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
           if(mat[i][j]==0)continue;

           if(mat[i][j]==1 && col1[i]==1 &&row1[j]==1)ans++;
       }
      }
      return ans;   
    }
};