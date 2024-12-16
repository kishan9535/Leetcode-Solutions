class Solution {
public:
 #define P pair<int,int>
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
      vector<pair<int,int>>vec;
      int n=nums.size();
      for(int i=0;i<n;i++){
        vec.push_back({nums[i],i});
      }
      
        priority_queue<P, vector<P>, greater<P>> pq(vec.begin(), vec.end());
      while(k--){
        P p=pq.top();
        pq.pop();
        int idx=p.second;
        int ele=p.first;
        int a=ele*multiplier;
        nums[idx]=a;
        pq.push({a,idx});
      }
        return nums;
    }
};