class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        if(t.length()>n) return "";

        unordered_map<char,int>mp;
        for(auto i:t){
            mp[i]++;
        }

        int required_cnt=t.length();
        int i=0,j=0;

        int window_size =INT_MAX;
        int start_i=0;

        while(j<n){
            char ch=s[j];

            if(mp[ch]>0) required_cnt--;
            mp[ch]--;

            while(required_cnt==0){
                int cur_window=j-i+1;
                if(window_size>cur_window){
                    window_size=cur_window;
                    start_i=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    required_cnt++;
                }
                i++;
            }
            j++;
        }
        return window_size==INT_MAX?"":s.substr(start_i,window_size);
    }
};