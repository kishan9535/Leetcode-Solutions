class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       for(int i=0;i<nums.size();i++){
           int a=1;
           a=nums[i]*nums[i];
           nums[i]=a;
       } 
       sort(nums.begin(),nums.end());
       return nums;
    }
};