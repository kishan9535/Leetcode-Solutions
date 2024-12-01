class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
       int ans=INT_MAX;
       int n=nums.size();
       bool found=false;
       for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if((j-i+1>=l) &&(j-i+1<=r) && sum>0){
                ans=min(ans,sum);
                found=true;
            }
            
        }
       }
       
       return found?ans:-1;
    }
};