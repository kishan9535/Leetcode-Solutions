class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
     int ans=0;
     unordered_map<int,pair<int,int>>xm;
     unordered_map<int,pair<int,int>>ym;

     for(auto it:buildings){
        int x=it[0];
        int y=it[1];
        if(!xm.count(x)){
        xm[x]={INT_MAX,INT_MIN};
        }
        if(!ym.count(y)){
        ym[y]={INT_MAX,INT_MIN};
        }
        xm[x].first =min(xm[x].first,y);
        xm[x].second =max(xm[x].second,y);

        ym[y].first =min(ym[y].first,x);
        ym[y].second =max(ym[y].second,x);
     }

     for(auto it:buildings){
        int x=it[0];
        int y=it[1];

        auto &xa=ym[y];
        auto &ya=xm[x];

       if(ya.first < y && y < ya.second &&  
    xa.first < x && x < xa.second)ans++;
     }
     return ans;   
    }
};