class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
      int ans=0;
      int n=matrix[0].size();
      int m=matrix.size();

      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          
          if(i>0 && matrix[i][j]){
            matrix[i][j]+=matrix[i-1][j];
          }
          
        }
        vector<int>row=matrix[i];
        sort(row.begin(),row.end(),greater<int>());

        for(int k=0;k<n;k++){
            int b=k+1;
            int h=row[k];
            ans=max(ans,(b*h));
        }
      }
      return ans;  
    }
};