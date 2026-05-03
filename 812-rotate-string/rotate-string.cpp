class Solution {
public:
    bool rotateString(string s, string goal) {

      int n=s.size();
      int m=goal.size();

      if(m!=n)return false;

      for(int i=0;i<m;i++){
        rotate(s.begin(),s.begin()+1,s.end());
        if(s==goal)return true;
      }
      return false;     
    }
};