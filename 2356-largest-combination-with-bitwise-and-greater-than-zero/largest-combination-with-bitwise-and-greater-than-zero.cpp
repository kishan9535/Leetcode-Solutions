class Solution {
public:
    int largestCombination(vector<int>& candidates) {
     vector<int>count(32,0);
     int maxi=0;
        
        for(int i=0;i<32;i++){
           for(auto &it :candidates){
            if((it & (1<<i))!=0){
                count[i]++;
            }
           }
           maxi=max(maxi,count[i]); 
        }
        return maxi;
    }
};