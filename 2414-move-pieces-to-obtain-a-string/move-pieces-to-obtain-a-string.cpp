class Solution {
public:
    bool canChange(string start, string target) {
     int n=start.size();
     int m=target.size();
     int i=0,j=0;
      while(i<n || j<m){
        while(i<n && start[i]=='_'){
            i++;
        }
        while(j<m && target[j]=='_'){
            j++;
        }
        if(i==n||j==m){
            return (i==n &&j==m);
        }
        if(i<j && start[i]=='L'&& target[j]=='L') return false;
         if(j<i && start[i]=='R'&& target[j]=='R') return false;
         if(start[i]!=target[j])return false;
         i++;j++;

      }
      return i==n && j==m;   
    }
};