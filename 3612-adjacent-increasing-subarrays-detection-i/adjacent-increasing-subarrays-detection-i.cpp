class Solution {
public:
      bool check(vector<int>& nums,int idx ,int k){
        for(int i=idx;i<idx+k-1;i++){
           if (nums[i] >= nums[i + 1]) return false;
        }
        return true;
      }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
       int cnt=0;
       int n=nums.size();
       for(int i=0;i<=n-2*k;i++){
        cout<<i<<endl;
         if(check(nums,i,k)&& check(nums,i+k,k))return true;
       }
        
       return false; 
    }
};