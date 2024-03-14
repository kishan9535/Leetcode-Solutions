class Solution {
public:
     bool isVowel(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
     }
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int n=s.length();
        int ans=0;
        int cnt=0;
        while(j<n){
         if(isVowel(s[j]))cnt++;
         
         if((j-i+1)>k){
            if(isVowel(s[i]))cnt--;
            i++;
         }
         ans=max(ans,cnt);

         j++;
        }
        return ans;
    }
};