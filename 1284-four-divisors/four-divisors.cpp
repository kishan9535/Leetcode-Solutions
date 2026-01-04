class Solution {
public:
    
    int find_sum(int num){
        int div=0;
        int sum=0;

        for(int i=1;i<=sqrt(num);i++){
            if(num%i==0){
                int rec=num/i;
                if(rec==i){
                    div++;
                    sum+=rec;
                }
                else{
                    div+=2;
                    sum+=i;
                    sum+=rec;
                }
            }
        }
         if(div==4) return sum;
        return 0;
    }

    int sumFourDivisors(vector<int>& nums) {
      int ans=0;
      int n=nums.size();

      for(int i=0;i<n;i++){
       ans+=find_sum(nums[i]);
      }
      return ans;  
    }
};