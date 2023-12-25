class Solution {
public:
  int n;
   int Mod=1e9+7;
   int t[100001];
   int solve(string &pressedKeys,int idx){
       if(idx==n)return 1;
       if(t[idx]!=-1)return t[idx];
       int maxkey=(pressedKeys[idx]=='7'||pressedKeys[idx]=='9') ?4:3;
       long long curIdx=idx,pressFreq=1,ans=0;
       while(pressFreq<=maxkey && pressedKeys[curIdx]==pressedKeys[idx]){
         ++curIdx;
         ++pressFreq;
         ans+=solve(pressedKeys,curIdx)%Mod;  
       }
       return  t[idx]=ans%Mod;
   }
    int countTexts(string pressedKeys) {
       n=pressedKeys.size();
       memset(t,-1,sizeof(t));
       return solve(pressedKeys,0); 
    }
};