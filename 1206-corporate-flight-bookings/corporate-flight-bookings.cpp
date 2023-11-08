class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n+1,0);
        for(auto i:bookings){
            ans[i[0]-1]+=i[2];
            ans[i[1]]-=i[2];
        }
        for(int i=1;i<ans.size();i++){
           ans[i]+=ans[i-1];
        }
        ans.pop_back();
        return ans;
    }
};