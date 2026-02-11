class Solution {
public:
   
    bool balanced(vector<int>& count){
     int size=0;
     for(int i=0;i<26;i++){
        if(count[i]!=0 && size==0){
            size=count[i];
        }
        else if(count[i] != 0 && count[i] != size){
                return false;
            }
     }
     return true;
    }
   
    int longestBalanced(string s) {

      int n=s.length();
      int ans=1;

     

      for(int i=0;i<n;i++){
          vector<int>count(26,0);
        for(int j=i;j<n;j++){
           count[s[j]-'a']++;

           if(balanced(count)){
            ans=max(ans,(j-i+1));
           }
        }
      }
      return ans;   
    }
};