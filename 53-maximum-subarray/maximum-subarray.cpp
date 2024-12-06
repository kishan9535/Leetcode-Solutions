class Solution {
public:
    // int  solve(vector<int>& nums,int idx){
    
    // }
    int maxSubArray(vector<int>& nums) {
      int n=nums.size();
      int max_sum=INT_MIN;
      int cur_sum=0;
      int start_idx=0;
      int end_idx=0;
      pair<int,int>p;
      bool flag=false;
      for(int i=0;i<n;i++){
        cur_sum+=nums[i];
        max_sum=max(max_sum,cur_sum);
        end_idx=i;
        if(cur_sum<0){
            start_idx=i+1;
           
            cur_sum=0;
        }
        
      }
      cout<<start_idx<<" "<<end_idx;
     return max_sum;
    }
};