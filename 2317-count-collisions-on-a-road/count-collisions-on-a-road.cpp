class Solution {
public:
    int countCollisions(string directions) {
      int n=directions.size();
      int ans=0;
      int i=0,j=n-1;
       while (i < n && directions[i] == 'L') i++;
        while (j >= 0 && directions[j] == 'R') j--;
        
        while(i<=j){
             if(directions[i] != 'S') {
                ans++;
            }
            i++;
        }
     return ans; 
    }
};