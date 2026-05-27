class Solution {
public:
    int numberOfSpecialChars(string word) {

     int n=word.size();
     int ans=0;

     vector<int>up(26,-1);
     vector<int>lo(26,-1);

     for(int i=0;i<n;i++){

        if(islower(word[i])){
            lo[word[i]-'a']=i;
        }
        else{
            if(up[word[i]-'A']==-1){
                up[word[i]-'A']=i;
            }
        }
     }

     for(int i=0;i<26;i++){
        if(up[i]!=-1 && lo[i]!=-1 && lo[i]<up[i])ans++;
     }

     
     return ans;
    }
};