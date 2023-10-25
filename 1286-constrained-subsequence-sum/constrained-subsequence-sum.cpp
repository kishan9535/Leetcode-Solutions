class Solution {
public:
    typedef pair<int, int> P;

int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
     vector<int>t(n,0);
       t=nums;
       priority_queue<P,vector<P>>pq;
       int result =t[0];
        pq.push({t[0], 0});
      for(int i=1;i<n;i++){
          while(!pq.empty() && pq.top().second<i-k){
              pq.pop();
          }
          t[i]=max(t[i],nums[i]+pq.top().first);
          result=max(result,t[i]);
          pq.push({t[i], i});

      }
      return result;   
    }
};