class Solution {
public:
    int totalMoney(int n) {
      if(n<=7) return n*(n+1)/2;
      int ans=0;
      int monday_money=1;
      while(n>0){
          int money=monday_money;
          for(int day=1;day<=min(7,n);day++){
              ans+=money;
              money++;
          }
          n-=7;
          monday_money++;
      }
      return ans;
    }
};