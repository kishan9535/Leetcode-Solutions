class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ans=0;
        unordered_map<char,int>mp;

        for(auto &it:text){
            mp[it]++;
        }

        int rem=10001;
        rem=min(rem,mp['a']);
        rem=min(rem,mp['b']);
        rem=min(rem,mp['n']);

        int doub=10001;
        doub=min(doub,mp['l']/2);
        doub=min(doub,mp['o']/2);

        return min(rem,doub);
    }
};