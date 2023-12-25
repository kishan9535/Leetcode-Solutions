class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
      int cnt=0;
       string pres=s;
        int n=pres.length();
      while(1){

        int has1=0;
        for(int i=0;i<n;i++){
         if(i+1<n &&(s[i]=='0' &&s[i+1]=='1')){
             swap(pres[i],pres[i+1]);
             has1=1;
         }
        }
        s=pres;
        if(has1==1)cnt++; 
        if(has1==0)break; 
      }
      return cnt;

    }
};