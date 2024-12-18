class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
      vector<int>ans;
      int n=prices.size();
      for(int i=0;i<n-1;i++){
        int curr=prices[i];
        int idx=i+1;
        int j;
        for( j=idx;j<n;j++){
            if(prices[j]<=curr){
                cout<<prices[j]<<endl;
               break;
            }
        }
        if(j>=n){
            ans.push_back(curr);
        }
        else{
            ans.push_back(abs(curr-prices[j]));
        }
      }
      ans.push_back(prices[n-1]);
      return ans;  
    }
};