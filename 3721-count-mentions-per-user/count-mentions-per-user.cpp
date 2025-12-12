class Solution {
public:

     void msg_event(vector<string>& events,vector<int>&ans,vector<int>&off){

        int time=stoi(events[1]);

        vector<string>ids;

        stringstream ss(events[2]);

        string token;
        while(ss >> token){
            ids.push_back(token);
        }

        for(auto &it: ids){
            if(it=="ALL"){
                for(int i=0;i<off.size();i++){
                    ans[i]++;
                }
            }
            else if(it=="HERE"){
              for(int i=0;i<ans.size();i++){
                if(off[i]==0 || off[i]+60<=time){
                    ans[i]++;
                }
              }
            }
            else{
               ans[stoi(it.substr(2))]++;
            }
        }
     }
   
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
      vector<int>ans(numberOfUsers);
      vector<int>off(numberOfUsers);

        auto cmp=[](vector<string>&v1, vector<string>&v2){
            int t1=stoi(v1[1]);
            int t2=stoi(v2[1]);
            
            if(t1==t2){
                return v1[0][1] > v2[0][1];
            }
  
           return t1<t2;
        };

      sort(events.begin(),events.end(),cmp);

      for(auto &it:events){

        if(it[0]=="MESSAGE"){
        msg_event(it,ans,off);
        }
        else if(it[0]=="OFFLINE"){
            int time= stoi(it[1]);
            int id= stoi(it[2]);
            off[id]=time;
        }
      }
      return ans;
    }
};