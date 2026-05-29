class Solution {
public:
    int minElement(vector<int>& nums){

      int mini=10001;    
      int n=nums.size();

      for(int i=0;i<n;i++){
        int d=nums[i];
        int sum=0;
        while(d){
            sum+=(d%10);
            d/=10;
        }
        mini=min(mini,sum);
      }
      return mini;   
    }
};