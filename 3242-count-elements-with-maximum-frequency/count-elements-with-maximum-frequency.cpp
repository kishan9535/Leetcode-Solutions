class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
       unordered_map<int,int>mp;
       for(auto i:nums){
           mp[i]++;
       }
       vector<int>v;
       for(auto i:mp){
           v.push_back(i.second);
       }
       sort(v.begin(),v.end());
       int n=v.size();
       int d=v[n-1];
       int ans=d;
       for(int i=n-2;i>=0;i--){
           if(v[i]==d){
               ans+=d;
           }
       }
       return ans; 
    }
};