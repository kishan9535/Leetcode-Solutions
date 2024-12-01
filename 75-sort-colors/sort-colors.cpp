class Solution {
public:
    void sortColors(vector<int>& nums) {
    //   vector<int>cnt(3,0);
    //   for(auto it: num){
    //      if(nums[i]==0)cnt[0]++;
    //      else if(nums[i]==2)cnt[1]++;
    //      else cnt[2]++;
    //   }
    //   int n= nums.size();
    //   int i=0;
    //   int j=0;
    //   while(i<n && j<cnt[0]){
    //     nums[i]=0;
    //   }
    //   j=0
    //   while(i<n && j<cnt[1]){
    //     nums[i]=1;
    //   }
    //   j=0;
    //   while(i<n && j<cnt[2]){
    //     nums[i]=2;
    //   }   
    sort(nums.begin(),nums.end()); 
    }
};