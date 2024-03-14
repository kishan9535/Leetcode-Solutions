class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       int n=nums.size();
       int i=0,j=0;
       int cnt=0;
       long long product=1;
       while(j<n){
        product*=nums[j];
        
        while(product>=k &&i<=j){
            product/=nums[i];
            i++;
        }
        cnt+=(j-i+1);
        j++;
       }
       return cnt; 
    }
};