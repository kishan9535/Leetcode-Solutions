class Solution {
public:
    long long solve(int n) {
        return n * (n + 1) / 2;
    }

    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int i = 0, j = 0;

        for(int i=0;i<n;i++){
            j=i;
            while(j+1<n && nums[j]!=nums[j+1]){
                j++;
            }
            int cnt=j-i+1;
            ans+=(long long)cnt*(cnt+1)/2;
            i=j;
        }
        return ans;
    }
};
