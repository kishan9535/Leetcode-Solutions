class Solution {
public:
   void Seive_of_primes(vector<bool>&seive, int n){
    seive[0] = true;
        seive[1] = true;
        for (int i = 2; i * i <= n; i++) {
            if (!seive[i]) {  
                for (int j = i * i; j <= n; j += i) {  
                    seive[j] = true;
                }
            }
        }
   }
    vector<int> closestPrimes(int left, int right) {
      vector<bool>seive(right+1,false);
      Seive_of_primes(seive,right);
      vector<int>primes;
      for(int i=left;i<=right;i++){
        if(!seive[i]){
            primes.push_back(i);
        }
      }
     if (primes.size() < 2) return {-1, -1}; 
    vector<int> ans = {-1, -1};
      int mini=INT_MAX;
      for(int i=1;i<primes.size();i++){
        if(primes[i]-primes[i-1]<mini){
           ans = {primes[i - 1], primes[i]};
            mini=primes[i]-primes[i-1];
        }
      }
      return ans;
    }
};