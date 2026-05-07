class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {

     int n=nums.size();
     vector<int>ans(n);
     vector<int>maxl(n);
     vector<int>minr(n);

     maxl[0]=nums[0];
     minr[n-1]=nums[n-1];

     for(int i=1;i<n;i++){
        maxl[i]=max(maxl[i-1],nums[i]);
     }
     for(int i=n-2;i>=0;i--){
        minr[i]=min(minr[i+1],nums[i]);
     }

     ans[n-1]=maxl[n-1];

     for(int i=n-2;i>=0;i--){
        if(maxl[i]<=minr[i+1]){
            ans[i]=maxl[i];
        }
        else{
            ans[i]=ans[i+1];
        }
     }

     return ans;

    }
};