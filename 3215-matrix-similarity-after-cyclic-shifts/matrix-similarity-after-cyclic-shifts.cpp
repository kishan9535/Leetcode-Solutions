class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
      int n=mat[0].size();
      int m=mat.size();

       k=(k%n);
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int curr=j;
            int shift;

            if(i%2==0){
                shift=(j+k)%n;
            }
            else{
                shift=(j-k+n)%n;
            }
          if(mat[i][j]!=mat[i][shift])return false;  
        }
      }
      return true;
    }
};