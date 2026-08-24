class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {

        int n=stones.size();
        vector<int>pref(n,0);
        vector<int>t(n,0);

        pref[0]=stones[0];

        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+stones[i];
        }

        t[n-1]=pref[n-1];

        for(int i=n-2;i>=1;i--){

            int take=pref[i]-t[i+1];
            int skip=t[i+1];

            t[i]=max(take,skip);
        }
        return t[1];
    }
};