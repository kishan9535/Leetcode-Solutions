class Solution {
public:

     void sieve(vector<int> &prime){
        prime[0]=false;
        prime[1]=prime[0];

        for(int i=2;i*i<1000;i++){
            if(prime[i]==true){
                for(int j=i*i;j<1000;j+=i){
                    prime[j]=false;
                }
            }
        }   
     }

    bool primeSubOperation(vector<int>& nums) {
       vector<int>prime(1000,true);
       sieve(prime);
       int n=nums.size();

       for(int i=n-2;i>=0;i--){
           if(nums[i]<nums[i+1])continue;

           for(int p=2;p<nums[i];p++){
              if(!prime[p])continue;
              
              if(nums[i]-p<nums[i+1]){
                nums[i]-=p;
                break;
              }
           }

           if(nums[i]>=nums[i+1]) return false;
       } 
       return true;
    }
};