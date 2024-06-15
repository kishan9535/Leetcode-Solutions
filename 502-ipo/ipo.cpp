class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
      
      int n=profits.size();
      vector<pair<int,int>>ans;
      for(int i=0;i<n;i++){
        ans.push_back({capital[i],profits[i]});
      }
      sort(ans.begin(),ans.end());

      priority_queue<int>pq;
      int i=0;

      while(k--){

        while(i<n && ans[i].first<=w){
            pq.push(ans[i].second);
            i++;
        }
          if(pq.empty()){
            return w;
          }
        w+=pq.top();
        pq.pop();
      }
      return w;  
    }
};