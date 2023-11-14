class Solution {
public:
  int solve(string a,string b){
      if(a[0]==b[0] && a[1]==b[1]){
          string s1=a.substr(2,2);
          string s2=b.substr(2,2);
          int a1=stoi(s1);
          int a2=stoi(s2);
          return abs(a1-a2);
         }
         else{
             string s1=a.substr(0,2);
             string s2=b.substr(0,2);
             string s3=a.substr(2,2);
             string s4=b.substr(2,2);
             int a1=stoi(s1);
             int b1=stoi(s2);
             int a2=stoi(s3);
             int b2=stoi(s4);
             int cnt=0;
             if(abs(a1-b1)==1){
                 if(a1<b1){
                     cnt+=60-a2;
                     cnt+=b2;
                 }
                 else{
                     cnt+=60-b2;
                     cnt+a2;
                 }
                 return cnt;
             }
             return 100;
         }
       
  }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
     int n=access_times.size();
        sort(access_times.begin(),access_times.end());
        unordered_map<string,vector<string>>mp;
        for(auto i:access_times){
            mp[i[0]].push_back(i[1]);
        }
        vector<string>ans;
      for(auto items :mp){
          if(items.second.size()<3)continue;
          else{
              for(int e=0;e<mp[items.first].size()-2;e++){
                  if(solve(mp[items.first][e],mp[items.first][e+2])<=59){
                      ans.push_back(items.first);
                      break;
                  }
              }
          }
          }
         return ans; 
      }
    
};