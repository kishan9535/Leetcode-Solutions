class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
     int n=rooms.size();
     vector<int>cnt(n,0);
     stack<int>st;
     cnt[0]=1;
     for(auto it:rooms[0]){
        st.push(it);
        cnt[it]=1;
     }
     while(!st.empty()){
        int a=st.top();
        cnt[a]=1;
        st.pop();
        for(auto it:rooms[a]){
            if(cnt[it]==0){
                st.push(it);
            }
        }
     }
     for(auto it:cnt){
        if(it==0)return false;
     }
     return true;
    }
};