class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
       int ans=0;
       int n=hours.size();
       for(int i=0;i<n;i++){
        int sum=hours[i];
        for(int j=i+1;j<n;j++){
           int hor=sum+hours[j];
           if(hor%24==0)ans++;
        }
       }
       return ans; 
    }
};