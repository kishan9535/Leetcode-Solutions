class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans=nums[0];
        int firstmini=INT_MAX;
        int secondmini=INT_MAX;

        for(int i=1;i<nums.size();i++){
            if(nums[i]<=firstmini){
                secondmini=firstmini;
                firstmini=nums[i];
            }
            else if(nums[i] < secondmini){
        secondmini = nums[i];
    }
           
        }
        ans+=(firstmini+secondmini);
        
        return ans;
    }
};