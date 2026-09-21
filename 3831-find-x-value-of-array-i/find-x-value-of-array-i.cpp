class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        int n=nums.size();

        vector<long long>ans(k,0);
        vector<long long>prev(k,0);

        for(int i=0;i<n;i++){

            vector<long long>cntt(k,0);

            int ce=nums[i]%k;
            cntt[ce]++;

            for(int j=0;j<=k-1;j++){
                int nw=((long long)j*nums[i]%k)%k;
                cntt[nw]+=prev[j];
            }

            prev=cntt;

            for(int x=0;x<=k-1;x++){
                ans[x]+=prev[x];
            }

        }

        return ans;

    }
};