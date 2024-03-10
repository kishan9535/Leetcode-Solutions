class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n=price.size();
        sort(price.begin(),price.end());
        int ans=1;
        int l=0,r=1e9;
        while(l<=r){
            int mid=l+(r-l)/2;
            int cntof_candies=1,last=price[0];
            for(int i=1;i<n;i++){
                if(price[i]-last>=mid){
                    cntof_candies++;
                    last=price[i];
                }
            }
            if(cntof_candies>=k){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};