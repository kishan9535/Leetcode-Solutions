class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
      vector<int>ans;
      int mod=1e9+7;
      for(int i=1;i<=n;i++){
        ans.push_back(i);
      }
      for(int i=1;i<k;i++){
        for(int j=1;j<n;j++){
            ans[j]=(ans[j]+ans[j-1])%mod;
        }
      }
  return ans[n-1];
    }
};