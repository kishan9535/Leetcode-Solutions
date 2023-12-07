class Solution {
public:
    int addMinimum(string word) {
     int letters_req=0;
     int n=word.length();
     int i=0;
     while(i<n){
       int valid_seq=0;
       if(word[i]=='a'){
           i++;
           valid_seq++;
       }
       if(word[i]=='b'){
           i++;
           valid_seq++;
       }
       if(word[i]=='c'){
           i++;
           valid_seq++;
       }
       letters_req+=3-valid_seq;
     }   
     return letters_req;
    }
};