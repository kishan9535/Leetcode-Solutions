class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=n+1;
        deque<int>deq;
        int i=0,j=0;
        vector<long long >pref(n,0);
        while(j<n){
            if(j==0){
                pref[0]=nums[0];
                
            }
            else{
                pref[j]=pref[j-1]+nums[j];

            }

            if(pref[j]>=k) ans=min(ans,j+1);

            while(!deq.empty() && pref[j]-pref[deq.front()]>=k){
                ans=min(ans,j-deq.front());
                deq.pop_front();
            }

            while(!deq.empty() && pref[j]<=pref[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(j);
            j++;

        }
       return ans==n+1?-1:ans;
    }
};