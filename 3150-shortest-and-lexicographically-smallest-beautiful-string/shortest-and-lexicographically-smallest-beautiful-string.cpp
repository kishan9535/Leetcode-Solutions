class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
    string ans;
    int n=s.length();
     int i=0,j=0;
      int cnt=0;
     while(j<n){
        if(s[j]=='1')cnt++;
        if(cnt==k){
        while(i<n && cnt==k ){
            string s1=s.substr(i,j-i+1);
            if(ans.size()==0 ||s1.size()<ans.size()){
                ans=s1;
            }
            else if(ans.size()==s1.size()){
                ans=min(ans,s1);
            }
            if(s[i]=='1'){
                cnt--;
                
            }
            i++;
        }
        }
        j++;
        
     }
     return ans;    
    }
};