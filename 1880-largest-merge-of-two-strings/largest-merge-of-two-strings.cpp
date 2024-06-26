class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans="";
        int i=0,j=0;
        int n=word1.size();
        int m=word2.size();
        while(i<n && j<m){
            if(word1.substr(i)>=word2.substr(j)){
                ans+=word1[i];
                i++;
            }
            else{
                ans+=word2[j];
                j++;
            }
        }
      
            while(i<n){
                ans+=word1[i];
                i++;
            }

        
            while(j<m){
                ans+=word2[j];
                j++;
            }
        
        return ans;
    }
};