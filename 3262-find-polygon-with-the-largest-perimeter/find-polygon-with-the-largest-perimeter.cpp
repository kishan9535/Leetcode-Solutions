class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
      sort(nums.begin(),nums.end());

        int n=nums.size();

        long long ans=0;

        vector<long long> pre(n);

        pre[0]=nums[0];

        for(int i=1;i<n;i++) pre[i]=pre[i-1]+nums[i];

        

        for(int i=2;i<n;i++){

         

            if(nums[i]<pre[i-1]) ans=max(ans,pre[i]);

        }

        if(ans==0) ans=-1;

        return ans;   
    }
};