class Solution {
public:
  bool isSet(int &x, int bit) {
        return x & (1 << bit);
    }

    bool setBit(int &x, int bit) {
        return x |= (1 << bit);
    }

    bool unsetBit(int &x, int bit) {
        return x &= ~(1 << bit);
    }
    int minimizeXor(int num1, int num2) {
       int x=num1;
       int cnt2=__builtin_popcount(num2);
       int cnt1=__builtin_popcount(num1);
        //if(cnt1==cnt2)return 0;
       int bit=0;
       if(cnt1<cnt2){
        while(cnt1<cnt2){
            if(!isSet(x,bit)){
                setBit(x,bit);
                cnt1++;
            }
            bit++;
        }
       }
       else if(cnt1>cnt2){
        while(cnt1>cnt2){
            if(isSet(x,bit)){
                unsetBit(x,bit);
                cnt1--;
            }
            bit++;
        }
       }
      return x;

    }
};