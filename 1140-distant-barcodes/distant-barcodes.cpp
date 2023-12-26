class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
     unordered_map<int,int>mp;
     int n=barcodes.size();
     for(auto i:barcodes){
         mp[i]++;
     }
     priority_queue<pair<int,int>>pq;
     for(auto i:mp){
         pq.push({i.second,i.first});
     }
     int i=0;
     vector<int>ans(n,0);
     while(!pq.empty()){
       pair<int,int> p=pq.top();
       pq.pop();
       while(p.first--){
         if(i>=n) i=1;
         ans[i]=p.second;
         i+=2;
       }  
     }
     return ans;
    }
};