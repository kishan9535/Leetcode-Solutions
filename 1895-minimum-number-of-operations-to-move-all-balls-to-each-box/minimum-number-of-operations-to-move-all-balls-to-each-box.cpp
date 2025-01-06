class Solution {
public:
    vector<int> minOperations(string boxes) {
      int n;
      n=boxes.size();
      vector<int>ans(n,0);
      int cum_sum=0;
      int cum_val=0;
      for(int i=0;i<n;i++){
        ans[i]=cum_sum;
        cum_val+=(boxes[i]=='0'?0:1);
        cum_sum+=cum_val;
      }
      cum_sum=0;
      cum_val=0;
      for(int i=n-1;i>=0;i--){
        ans[i]+=cum_sum;
        cum_val+=(boxes[i]=='0'?0:1);
        cum_sum+=cum_val;
      }
      return ans;  
    }
    
};