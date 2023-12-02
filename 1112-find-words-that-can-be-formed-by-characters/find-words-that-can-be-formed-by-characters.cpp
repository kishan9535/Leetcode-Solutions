class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
      vector<int>ch(26,0);
      for(auto i:chars){
          ch[i-'a']++;
      }
      int result=0;
      for(auto wo:words){
        vector<int>wc(26,0);
        for(auto c:wo){
            wc[c-'a']++;
        }
        bool ok=true;
        for(int i=0;i<26;i++){
            if(wc[i]>ch[i]){
                ok=false;
                break;
            }
        }
        if(ok==true){
            result+=wo.length();
        }
      }
      return result;
    }
};