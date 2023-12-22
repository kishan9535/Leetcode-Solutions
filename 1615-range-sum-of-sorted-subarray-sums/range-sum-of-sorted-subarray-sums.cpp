class Solution {
public:
int Mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
       vector<int>sub;
       int no=nums.size();
       for(int i=0;i<no;i++){
           int ans=0;
           for(int j=i;j<no;j++){
               ans+=nums[j];
               sub.push_back(ans);
           }
       }
       sort(sub.begin(),sub.end());
       int ans=accumulate(sub.begin()+left-1,sub.begin()+right,0LL)%Mod;
       return ans; 
    }
};