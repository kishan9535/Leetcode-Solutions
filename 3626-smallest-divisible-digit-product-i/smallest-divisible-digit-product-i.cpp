class Solution {
public:
     int pro(int num){
         int p=1;
         while(num){
             int d=num%10;
             p*=d;
             num/=10;
         }
         return p;
     }
    int smallestNumber(int n, int t) {
      int curr=n;
        while(1){
          int p=pro(curr);
            if(p%t==0)return curr;
            curr++;
        }
        return curr;
    }
};