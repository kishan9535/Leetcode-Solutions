class Solution {
public:
     bool isVovel(char ch){
         return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
         }
    int beautifulSubstrings(string s, int k) {
       int n=s.length();
       int result=0;
       for(int i=0;i<n;i++){
           int con=0,vov=0;
           for(int j=i;j<n;j++){
             if(isVovel(s[j])){
                 vov++;
             }
             else{
                 con++;
             }
           
             if(con==vov && (con*vov)%k==0){
                 result++;
             }
           }
           
       }
       return result; 
    }
};