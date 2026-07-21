class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int n=s.length();
        int ans=0;


         
        for(int i=0;i<n;i++){
            if(s[i]=='1')ans++;
        }

      

        int maxi=0;
        vector<int>pref;

        int i=0;

        while(i<n){

            if(s[i]=='0'){

                int idx=i;

                while(i<n && s[i]=='0'){
                    ++i;
                }
                pref.push_back(i-idx);
            }
            else{
                ++i;
            }
        }

        for(int i=1;i<pref.size();i++){
            maxi=max(maxi,(pref[i]+pref[i-1]));
        }

        return ans+maxi;
    }
};