class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n=arr.size();
        int ans=INT_MAX;
        int i=0,j=0;
        vector<int>mini(n,INT_MAX);
        int bestminlen=INT_MAX;
        int cur_sum=0;

        while(j<n){
            cur_sum+=arr[j];

            while(i<j && cur_sum>target){
                cur_sum-=arr[i++];
            }

            if(cur_sum==target){
                int l=j-i+1;
               
               if(i>0 && mini[i-1]!=INT_MAX){
                ans=min(ans,l+mini[i-1]);
               }
               bestminlen=min(bestminlen,l);

            }
            mini[j]=bestminlen;
            j++;

        }

        return ans==INT_MAX?-1:ans;
        
    }
};