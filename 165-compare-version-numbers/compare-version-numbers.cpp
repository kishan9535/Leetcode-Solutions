class Solution {
public:
    
     vector<string> get_tokens(string version){
       stringstream ss(version);
       string token="";
       vector<string>tokens;
       while(getline(ss,token,'.')){
         tokens.push_back(token);
       }
       return tokens;
     }


    int compareVersion(string version1, string version2) {
     vector<string> ans1=get_tokens(version1);
     vector<string> ans2=get_tokens(version2);   
     int n=ans1.size();
     int m=ans2.size();
      int i=0;
     while(i< m ||i<n){
        int a =i<n?stoi(ans1[i]):0;
        int b=i<m? stoi(ans2[i]):0;
        if(a<b)return -1;
        else if(a>b)return 1;
        else i++;
     }
     return 0;
    }
};