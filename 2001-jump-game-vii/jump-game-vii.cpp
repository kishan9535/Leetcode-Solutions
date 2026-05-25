class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
       int n=s.length();
       vector<int>t(n,0);

       int cnt=0;
       t[0]=1;

       for(int i=1;i<=n-1;i++){
          if(i-minJump>=0){
            cnt+=t[i-minJump];
          }

          if(i-maxJump-1>=0){
            cnt-=t[i-maxJump-1];
          }

          if(s[i]=='0' && cnt>0){
            t[i]=1;
          }
       }
       return t[n-1];
    }
};