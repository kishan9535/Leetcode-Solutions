class Solution {
public:
    bool isVowel(char c){
        char a=tolower(c);
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') return true;
        return false;
    }
    string sortVowels(string s) {
    string temp="AEIOUaeiou";
    int j=0;
    unordered_map<char,int>mp;
    for(auto i:s){
        if(isVowel(i)){
        mp[i]++;
        }
    }
    for(int i=0;i<s.length();i++){
        if(isVowel(s[i])){
           while(mp[temp[j]]==0){
            j++;
           }
           s[i]=temp[j];
           mp[temp[j]]--;
        }
    }
   return s;
    }
};