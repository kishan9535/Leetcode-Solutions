class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
     int n=words.size();
     int ans=INT_MAX;

     for(int i=0;i<n;i++){
        if(words[i]==target){
            int d=abs(startIndex-i);
            int cir_d=(n-d);
            ans=min({ans,d,cir_d});

        }
     }
   return ans==INT_MAX?-1:ans;
    }
};