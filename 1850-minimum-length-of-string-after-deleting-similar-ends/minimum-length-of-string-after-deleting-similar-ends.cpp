class Solution {
public:
    int minimumLength(string s) {
     int n=s.length();
     int i=0,j=n-1;

     while(i<j && s[i]==s[j]){
        char ch=s[i];
        while(i<j && ch==s[i]){
            i++;
        }
         while(j>=i && ch==s[j]){
             j--;
         }
     }
     return j-i+1;   
    }
};