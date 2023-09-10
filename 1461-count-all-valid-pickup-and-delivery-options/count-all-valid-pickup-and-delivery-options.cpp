class Solution {
public:
int M=1e9+7;
    int countOrders(int n) {
       if(n==1) return 1;
       long long res=1;
       for(int i=2;i<=n;i++){
           int spaces=(i-1)*2+1;
           int posibility=spaces*(spaces+1)/2;
           res*=posibility;
           
           res%=M;
       } 
       return res;
    }
};