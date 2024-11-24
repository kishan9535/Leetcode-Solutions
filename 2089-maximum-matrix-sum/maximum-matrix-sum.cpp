class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
      long long ans=0;
      int mini=INT_MAX;
      int neg_cnt=0;

      int n=matrix[0].size();
      int m=matrix.size();
        bool neg=false;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]<0){
                neg_cnt++;
                neg=true;
            }
            int ele=abs(matrix[i][j]);
            mini=min(mini,ele);
            ans+=ele;
        }
      }
      if(neg_cnt%2==0)return ans;
      return ans-2*(mini);
    }
};