class Solution {
public:
  long MOD=1e9+7;
  long long power(long x,long n){
      if(n==0)return 1;
      long long temp=power(x,n/2)%MOD;
      if(n%2==0){
          return (temp*temp)%MOD;
      }
      return (x*(temp*temp))%MOD;
  }
    int countGoodNumbers(long long n) {
      long even=(n+1)/2;
      long odd=n/2;
      long first=power(5,even)%MOD;
      long second=power(4,odd)%MOD;

      return (int)((first*second)%MOD);
    }
};