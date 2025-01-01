class Solution {
public:
    int maxScore(string s) {
     int ans=0;
     int cnt1=count(s.begin(),s.end(),'1');
     int n=s.length();
     int cnt0=0;
     for(int i=0;i<n-1;i++){
        if(s[i]=='0')cnt0++;
        else{
            cnt1--;
        }
        ans=max(ans,(cnt0+cnt1));
     }
     return ans;
    }
};