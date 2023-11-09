class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
     int ans=0;
     unordered_map<int,int>mp;
     for(auto i:tasks){
         mp[i]++;
     }
     for(auto i:mp){
         int cnt=i.second;
         if(cnt==1)return -1;

         if(cnt%3==0){
             ans+=cnt/3;
         }
         else{
             ans+=(cnt/3)+1;
         }
     }
     return ans;   
    }
};