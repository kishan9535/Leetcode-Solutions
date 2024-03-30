class Solution {
public:
    int cnt_subarrays(vector<int>& nums,int k){
        unordered_map<int,int>mp;
        int i=0,j=0;
        int n=nums.size();
        int cnt=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return cnt_subarrays(nums,k)-cnt_subarrays(nums,k-1);
    }
};