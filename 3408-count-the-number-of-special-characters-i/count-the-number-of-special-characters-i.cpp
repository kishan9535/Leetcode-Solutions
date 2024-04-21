class Solution {
public:
    int numberOfSpecialChars(string word) {
       unordered_set<char>upper;
       unordered_set<char>lower;
        
        for(auto i:word){
            if(islower(i))lower.insert(i);
            else upper.insert(i);
        }
        int ans=0;
        for(auto i: lower){
            if(upper.find(toupper(i))!=upper.end()){
                ans++;
            }
        }
        return ans;
    }
};