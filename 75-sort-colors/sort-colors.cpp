class Solution {
public:
    void sortColors(vector<int>& nums) {
      vector<int>cnt(3,0);

      for(auto it: nums){
        if(it==0)cnt[0]++;
        if(it==1)cnt[1]++;
        if(it==2)cnt[2]++;
      }
      cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2];
      int n= nums.size();
      int i=0;
      int k=cnt[0];
      while( k--){
        nums[i]=0;
        i++;
      }
      k=cnt[1];
      while(k--){
        nums[i]=1;
        i++;
      }
      k=cnt[2];
      while(k--){
        nums[i]=2;
        i++;
      }    
    }
};