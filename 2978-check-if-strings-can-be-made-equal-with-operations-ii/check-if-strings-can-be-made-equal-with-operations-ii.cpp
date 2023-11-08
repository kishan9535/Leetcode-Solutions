class Solution {
public:
    bool checkStrings(string s1, string s2) {
      string a,b,c,d;
      for(int i=0;i<s1.length();i+=2){
          a+=s1[i];
          b+=s2[i];
      }
       for(int i=1;i<s2.length();i+=2){
          c+=s1[i];
          d+=s2[i];
      }
      sort(a.begin(),a.end());
       sort(b.begin(),b.end());
        sort(c.begin(),c.end());
         sort(d.begin(),d.end());    
         return a==b && c==d;
    }
};