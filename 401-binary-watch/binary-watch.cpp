class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
     vector<string>ans;

     for(int i=0;i<=11;i++){
        for(int j=0;j<=59;j++){

            if(__builtin_popcount(i)+__builtin_popcount(j)==turnedOn){
              string a=to_string(i);
              string b;
              if(j<10){
                b+='0';
              }
              b+=to_string(j);

              string c= a+ ':' +b;
              ans.push_back(c);
            }
        }
        
     } 
     return ans;  
    }
};