class Solution {
public:
    long long countSubstrings(string s, char c) {
        int n=s.length();
        long long cnt=0,ans=0;
        
        for(auto i:s){
            if(i==c){
                ans+=(1+cnt);
                cnt++;
            }
        }
       return ans;
    }
};