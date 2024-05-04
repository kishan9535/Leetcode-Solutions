class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
      priority_queue<int,vector<int>,greater<int>>pq;
      for(auto i:nums){
        pq.push(i);
      }
      nums.clear();
      while(!pq.empty()){
       nums.push_back(pq.top());
       pq.pop();
      }
      return nums;  
    }
};