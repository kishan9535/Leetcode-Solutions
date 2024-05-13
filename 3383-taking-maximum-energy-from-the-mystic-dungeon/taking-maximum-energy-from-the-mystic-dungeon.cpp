class Solution {
public:
int n;
    int t[100001];
    int solve(int idx,vector<int>& energy, int k){
        if(idx>=n)return 0;
        if(t[idx]!=-1)return t[idx];
        int pick=energy[idx]+solve(idx+k,energy,k);
        
        return t[idx]=pick;
    }
    int maximumEnergy(vector<int>& energy, int k) {
      n=energy.size();
      memset(t,-1,sizeof(t));
      int maxi = INT_MIN;
        for (int i = 0; i < n; i++) { // Loop through all starting points
            maxi = max(maxi, solve(i, energy, k));
        }
        return maxi; 
    }
};