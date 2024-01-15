class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> w,l;
        unordered_map<int,int>t;
        for(auto i:matches)
        {
            w.insert(i[0]),l.insert(i[1]);
            t[i[1]]++;
        }
        vector<int> v1,v2;
        for(auto i:w)
        {
            if(t.find(i)==t.end())
            v1.push_back(i);
        }
        for(auto i:l)
        {
            if(t[i]==1)
            v2.emplace_back(i);
        }
        return {v1,v2};
    }
};