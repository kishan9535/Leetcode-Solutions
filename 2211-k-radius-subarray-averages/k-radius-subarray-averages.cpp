class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        int window_size=2*k+1;
        vector<int>ans(n,-1);   

        if(n<window_size)return ans;
        vector<long long >prefix_sum(n+1,0);
        //prefix_sum[0]=nums[0];
        for(int i=0;i<n;i++){
            prefix_sum[i+1]=prefix_sum[i]+nums[i];
        }
        for(int i=k;i+k<n;++i){
            ans[i]=(prefix_sum[i+k+1]-prefix_sum[i-k])/window_size;
        }
       return ans;
    }
};
//  7 11 14 23 24 32 37 39 45
//  0 1  2  3  4   5  6 7  8

// (37-7)/3=10
//  