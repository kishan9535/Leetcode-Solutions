class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>mp;
        int ans=INT_MAX;
        int n=cards.size();
        for(int i=0;i<n;i++){
            if(mp.find(cards[i])!=mp.end()){
                ans=min(ans,(i-mp[cards[i]]+1));
            }
            mp[cards[i]]=i;
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};