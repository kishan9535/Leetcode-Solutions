class Solution {
public:
    bool canAliceWin(int n) {
      int stones=10;
      int cnt=0;
      while(1){
        if(n>=stones){
            n-=stones;
            stones--;
            cnt++;
        }
        else{
            break;
        }
      }
      return (cnt%2); 
    }
};