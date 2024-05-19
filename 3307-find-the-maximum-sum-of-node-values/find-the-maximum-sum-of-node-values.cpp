class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
      long long prefix_sum=0;
      int n=nums.size();
      vector<int>Xor_diff;

        for(int i=0;i<n;i++){
            prefix_sum+=nums[i];
            Xor_diff.push_back((nums[i]^k)-nums[i]);
        }
        sort(Xor_diff.begin(),Xor_diff.end(),greater<int>());
       
        for(int i=0;i<n-1;i+=2){
            long long ans_pair=Xor_diff[i]+Xor_diff[i+1];
            if(ans_pair>0){
                prefix_sum+=ans_pair;
            }
        }
        return prefix_sum;
    }
};