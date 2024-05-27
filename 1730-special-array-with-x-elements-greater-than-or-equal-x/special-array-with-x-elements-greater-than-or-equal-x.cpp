class Solution {
public:

     int find_greater(vector<int>& nums,int key){
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=key)cnt++;
        }
        return cnt;;
     }
    int specialArray(vector<int>& nums) {
      int n=nums.size();
      for(int i=1;i<=n;i++){
        if(i==find_greater(nums,i)){
            return i;
        }
      }
      return -1;  
    }
};