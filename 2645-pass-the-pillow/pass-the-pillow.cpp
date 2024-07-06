class Solution {
public:
    int passThePillow(int n, int time) {
      int pos=1;
      int dir=1;
      int i=1;
      while(i<=time){
        if(pos==n){
            dir=-1;
            //pos+=dir;
        }
        if(pos==1){
            dir=1;
            //pos+=dir;
        }
        i++;
        pos+=dir;
      }
      return pos;
    }
};