class Solution {
public:
    bool canBeValid(string s, string locked) {
      int n= s.length();
      if(n%2!=0)return false;
      int l_cnt=0,r_cnt=0;
      for(int i=0;i<n;i++){
         if(s[i]=='(' || locked[i]=='0'){
            l_cnt++;
         }
         else{
            l_cnt--;
         }
         if(l_cnt<0)return false;
      }
      for(int i=n-1;i>=0;i--){
        if(s[i]==')'|| locked[i]=='0'){
            r_cnt++;
        }
        else{
            r_cnt--;
        }
        if(r_cnt<0)return false;
      }
      return true;
    }
};