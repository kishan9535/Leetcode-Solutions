class Solution {
public:
    bool isVowel(char ch){
        char c =tolower(ch);
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    bool isValid(string word) {
        bool con=false;
        bool vov=false;
        if(word.size()<3)return false;
        for(int i=0;i<word.size();i++){
            char a=word[i];
            if((a>='a'&& a<='z')|| (a>='A'&&a<='Z')){
                con|=!isVowel(a);
                vov|=isVowel(a);
            }
            else if(a>='0'&&a<='9'){
                continue;
            }
            else return false;
        }
        return (con && vov);
    }
};
