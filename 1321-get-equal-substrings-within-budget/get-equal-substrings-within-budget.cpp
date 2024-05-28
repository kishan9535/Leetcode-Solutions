class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0;
        int n=s.length();
        int i=0,j=0;
        int temp_cost=0;
        while(j<n){
            int diff=abs(s[j]-t[j]);
            temp_cost+=diff;
            while(temp_cost>maxCost){
                int d=abs(s[i]-t[i]);
                temp_cost-=d;
                i++;
            }
            ans=max(ans,(j-i+1));
            j++;

        }
      return ans;
    }
};