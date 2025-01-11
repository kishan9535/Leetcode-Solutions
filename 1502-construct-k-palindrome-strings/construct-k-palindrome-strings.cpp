class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        // This Day 11 jan i got my first interview selection 90% i almost got selected ..
        // i will work hard and be consistent. keep it up kishan good days are comming ahead.
        if(k>n)return false;
        if(k==n)return true;
        vector<int>cnt(26,0);
        int odd_cnt=0;
        for(auto it:s){
            cnt[it-'a']++;
        }
        for(auto it: cnt){
            if(it%2!=0)odd_cnt++;
        }
        return odd_cnt<=k;
    }
};