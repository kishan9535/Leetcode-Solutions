class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
     long long ans=0;
     int mini=INT_MAX;
     int neg_cnt=0;
     int n=matrix[0].size();
     int m=matrix.size();

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]<0){
                neg_cnt++;
                ans+=abs(matrix[i][j]);
                
            }
            else{
                ans+=matrix[i][j];
            }
            mini=min(mini,abs(matrix[i][j]));

        }
     }
     if(neg_cnt%2==0)return ans;

     return ans-2*mini;   
    }
};