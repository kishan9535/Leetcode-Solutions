class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int ans=0;
        int n=nums.size();

        if(k==n){
            return *max_element(nums.begin(),nums.end());
        }

        int freq[51]={0};

        for(auto &it:nums){
            freq[it]++;
        }

        if(k==1){
            for(int i=50;i>=0;i--){
                if(freq[i]==1)return i;
            }
        }

        ans=-1;

        if(freq[nums[0]]==1){
            ans=max(ans,nums[0]);
        }

        if(freq[nums[n-1]]==1){
            ans=max(ans,nums[n-1]);
        }

        return ans;

        
    }
};