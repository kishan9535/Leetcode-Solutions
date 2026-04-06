class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
       unordered_set<string>st;
       for(auto it: obstacles){
        string key=to_string(it[0])+ "_"+to_string(it[1]);
        st.insert(key);
       }
        int x=0,y=0;
        int max_dis =0;
        pair<int,int>dir={0,1};

        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){
                dir={dir.second,-dir.first};
            }
            else if(commands[i]==-2){
                dir={-dir.second,dir.first};
            }
            else{
                for(int k=0;k<commands[i];k++){
                    int new_x=x+dir.first;
                    int new_y=y+dir.second;
                    string new_key=to_string(new_x)+"_"+to_string(new_y);
                    if(st.find(new_key)!=st.end()){
                        break;
                    }
                    x=new_x;
                    y=new_y;
                }
            }
            max_dis=max(max_dis,(x*x +y*y));
        }

      return max_dis;
    }
};