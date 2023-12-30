class Solution {
public:
    bool makeEqual(vector<string>& words) {
     unordered_map<char,int>mp;
     int n=words.size();
     for(auto &it:words){
         for(int i:it){
             mp[i]++;
         }
     }
       for(auto i:mp){
           if(i.second%n!=0)return false;
       }
     return true;   
    }
};