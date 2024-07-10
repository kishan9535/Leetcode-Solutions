class Solution {
public:
    int minOperations(vector<string>& logs) {
     int cnt=0;
     for(int i=0;i<logs.size();i++)
     {
         if(logs[i]== "./") 
         {continue;}
         else if(logs[i]=="../")
         {
             if(cnt>0)cnt--;
         }
         else
         cnt++;
     }   
     return cnt;
    }
};