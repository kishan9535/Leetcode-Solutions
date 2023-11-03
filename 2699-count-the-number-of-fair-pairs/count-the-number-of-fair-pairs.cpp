class Solution {
public:
    long long countAns(vector<int>& nums, int k){
        long long cnt=0;
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]<=k){
                cnt+=(j-i);
                i++;
            }
            else{
                j--;
            }
        }
        return cnt;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
      sort(nums.begin(),nums.end()); 
      return countAns(nums,upper)-countAns(nums,lower-1); 
    }
};