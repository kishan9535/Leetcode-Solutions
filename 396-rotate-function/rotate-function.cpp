class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

      int n=nums.size();
      int sum=0;
      int f=0;
      int maxi=0;
 
      for(int i=0;i<n;i++){
        sum+=nums[i];
        f+=(i*nums[i]);
      }
      maxi=f;

      for(int i=0;i<n;i++){
         int nf=f+sum-n*nums[n-i-1];
         maxi=max(maxi,nf);
         f=nf;
      }

      return maxi;

    }
};