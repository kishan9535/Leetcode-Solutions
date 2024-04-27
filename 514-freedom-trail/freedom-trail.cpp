class Solution {
public:
  int t[101][101];
     int Count_steps(int ring_idx,int i,int n){
        int dist=abs(i-ring_idx);
        int rev_dist=abs(n-dist);
        int mini=min(dist,rev_dist);
        return mini;
     }
    int solve(int ring_idx,int key_idx,string& ring, string& key){
     if(key_idx>=key.length()){
        return 0;
     }
     if(t[ring_idx][key_idx]!=-1)return t[ring_idx][key_idx];
     int ans=INT_MAX;
     for(int i=0;i<ring.size();i++){
      if(ring[i]==key[key_idx]){
        int total_steps=1+Count_steps(ring_idx,i,ring.length())+solve(i,key_idx+1,ring,key);
        ans=min(ans,total_steps);
      }
     }
     return t[ring_idx][key_idx]= ans;
    }

    int findRotateSteps(string ring, string key) {
        memset(t,-1,sizeof(t));
       return solve(0,0,ring,key); 
    }
};