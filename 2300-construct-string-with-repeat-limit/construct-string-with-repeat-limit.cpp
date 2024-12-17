class Solution {
public:
   char find_prev(char c,vector<int>&cnt){
       int idx = c - 'a';
        for (int i = idx - 1; i >= 0; i--) {
            if (cnt[i] > 0) {
                return 'a' + i;
            }
        }
        return '$'; 
   }
    string repeatLimitedString(string s, int repeatLimit) {
     string ans="";
     vector<int>cnt(26,0);
     for(auto it: s){
        cnt[it-'a']++;
     }
     for(int i=25;i>=0;i--){
       
       char ch='a'+i;
       while(cnt[i]>0){
        int count=min(repeatLimit,cnt[i]);
        cnt[i]-=count;
        while(count--){
            ans+=ch;
        }
        
        if(cnt[i]>0){
            char p=find_prev(ch,cnt);
            if(p=='$')return ans;
            else{
                ans+=p;
                cnt[p-'a']--;
            }
        }
     }
     }
     return ans;   
    }
};