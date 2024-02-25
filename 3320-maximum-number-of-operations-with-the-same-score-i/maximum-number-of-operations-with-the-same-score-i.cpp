class Solution {
public:
    int maxOperations(vector<int>& nums) {
       int score=1;
       int diff=nums[0]+nums[1];
       int n=nums.size();
       for(int i=2;i<n-1;i+=2){
           if(nums[i]+nums[i+1]==diff)score++;
       
       else break;
       }
       return score; 
    }
};