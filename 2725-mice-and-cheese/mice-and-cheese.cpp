class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    vector<pair<int,int>>dif;
    for(int i=0;i<reward1.size();i++){
        int d=reward1[i]-reward2[i];
        dif.push_back({d,i});
    }
     sort(dif.begin(),dif.end());
     reverse(dif.begin(),dif.end());
     int ans=0;
     set<int>st;
     for(int i=0;i<k;i++){
         int t=dif[i].second;
         ans+=(reward1[t]);
         st.insert(t);
     } 
     for(int i=0;i<reward2.size();i++){
         if(st.find(i)==st.end()){
             ans+=reward2[i];
         }
     }
     return ans;      
    }
};