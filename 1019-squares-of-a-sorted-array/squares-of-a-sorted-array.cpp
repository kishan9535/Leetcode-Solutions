class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int n=nums.size();
      vector<int>ans(n,0);
      int i=0,j=n-1;
      n=n-1;
      while(i<=j){
          int l=nums[i]*nums[i];
          int r=nums[j]*nums[j];
          if(l>r){
            ans[n--]=l;
            i++;
          }
          else{
              ans[n--]=r;
              j--;
          }

      }
      return ans;    
    }
};