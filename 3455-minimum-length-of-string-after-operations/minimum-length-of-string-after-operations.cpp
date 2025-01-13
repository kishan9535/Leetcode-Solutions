class Solution {
public:
    int minimumLength(string s) {
     int ans=0;
     vector<int>cnt(26,0);
     for(auto it: s){
        cnt[it-'a']++;
     }
     for(auto it: cnt){
        if(it>0){
            if(it%2==0)ans+=2;
            else ans+=1;
        }
     }
     return ans;   
    }
};