class Solution {
public:
    void Next_neighbours(queue<string>&qu,string& curr,unordered_set<string>&st){
    
      for(int i=0;i<4;i++){
        char ch=curr[i];

        char dec=ch=='0'?'9':ch-1;
        char inc=ch=='9'?'0':ch+1;

        curr[i]=dec;
        if(st.find(curr)==st.end()){
            st.insert(curr);
            qu.push(curr);
        }
        curr[i]=inc;
        if(st.find(curr)==st.end()){
            st.insert(curr);
           qu.push(curr); 
        }
        curr[i]=ch;
      }
      return;
    }


    int openLock(vector<string>& deadends, string target) {
       
       string start="0000";
       unordered_set<string>st(deadends.begin(),deadends.end());
       queue<string>qu;
       qu.push(start); 
       int level=0;
        if(st.find(start)!=st.end())return -1;
       while(!qu.empty()){
        int n=qu.size();
        while(n--){
            string curr=qu.front();
            qu.pop();
              
            if(curr==target)return level;
           
             Next_neighbours(qu,curr,st);
        }
        level++;
       }
       return -1;
    }
};