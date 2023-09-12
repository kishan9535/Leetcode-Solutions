class Solution {
public:
    int minDeletions(string s) {
        unordered_set<int> st;
        vector<int> freq(26,0);
        int ans =0;
        for(auto &i: s){
            freq[i-'a']++;
        }

        for(int i=0;i<26;i++){
            while(freq[i]>0 && st.find(freq[i])!=st.end()){
                freq[i]--;
                ans++;
            }
            st.insert(freq[i]);
        }
        return ans;
    }
};