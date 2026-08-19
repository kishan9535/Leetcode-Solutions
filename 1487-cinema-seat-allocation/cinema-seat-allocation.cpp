class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        int ans=0;

        unordered_map<int,unordered_set<int>>mp;

        for(auto &it:reservedSeats){
            int r=it[0];
            int c=it[1];

            mp[r].insert(c);
        }
        ans+=(n-mp.size());
        ans*=2;


        for(auto &[r,c]:mp){

            auto check=[&](int num){
               return !(c.find(num)!=c.end());
            };

            int g1=check(2)&&check(3)&&check(4)&&check(5);
            int g2=check(4)&&check(5)&&check(6)&&check(7);
            int g3=check(6)&&check(7)&&check(8)&&check(9);

            if(g1&&g3){
                ans+=2;
            }
            else if(g1||g2||g3){
                ans++;
            }
        }

        return ans;
    }
};