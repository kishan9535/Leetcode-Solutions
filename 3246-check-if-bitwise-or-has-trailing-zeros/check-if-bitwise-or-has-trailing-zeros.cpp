class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
      int n=nums.size();
      int evencnt=0;
      for(int i=0;i<n;i++){
          if(!(nums[i]&1))evencnt++;
          if(evencnt==2) return true;
      }
      return false;
    }
};