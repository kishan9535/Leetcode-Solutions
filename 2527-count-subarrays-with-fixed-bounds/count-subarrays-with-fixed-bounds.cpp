class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        int i=0;
        long long ans=0;
        int minPos=-1;
        int maxPos=-1;
        int culp_Idx=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==minK){
                minPos=i;
            }
             if(nums[i]==maxK){
                maxPos=i;
            }
            if(nums[i]>maxK || nums[i]<minK){
                culp_Idx=i;
            }
            int smaller=min(minPos,maxPos);
            int temp=smaller-culp_Idx;
            ans+=(temp<=0)?0:temp;
        }
        return ans; 
    }
};