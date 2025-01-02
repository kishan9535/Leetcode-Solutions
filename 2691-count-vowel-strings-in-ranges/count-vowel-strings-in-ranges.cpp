class Solution {
public:
    bool isvovel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
       vector<int>pref;
       int sum=0;
       for(auto it: words){
        string t=it;
        int m=t.length();
        if(isvovel(t[0])&& isvovel(t[m-1])){
          sum++;
        }
        pref.push_back(sum);
       }
       vector<int>ans;
       for(auto it: queries){
        int l=it[0];
        int r=it[1];
         int a= pref[r]-(l==0?0:pref[l-1]);
         ans.push_back(a);
       }
       return ans; 
    }
};