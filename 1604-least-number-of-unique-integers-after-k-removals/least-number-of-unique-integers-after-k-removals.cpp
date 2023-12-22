class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
      unordered_map<int,int>mp;
      int ans=0;
      for(auto i:arr){
          mp[i]++;
      }
      vector<int>freq;
      for(auto i:mp){
          freq.push_back(i.second);
      }
     sort(freq.begin(),freq.end());
     int n=freq.size();
     int i=0;
     while(k>0){
         k-=freq[i];
         ans++;
         if(k>=0){
             i++;
         };
     }
     return n-i;  
    }
};