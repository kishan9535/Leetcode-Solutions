class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
       vector<int>ans;

       int Xor=0;
       for(auto &it: nums){
        Xor^=it;
       }
       int mask=((1<<maximumBit)-1); 

       int n=nums.size();

       for(int i=0;i<n;i++){
          int k= Xor^mask;
          ans.push_back(k);
          Xor^=nums[n-i-1];
       }
       return ans;
    }
};