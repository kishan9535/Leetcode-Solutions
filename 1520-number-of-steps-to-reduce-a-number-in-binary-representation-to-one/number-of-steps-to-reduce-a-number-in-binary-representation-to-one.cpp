class Solution {
public:
void odd_reducer(string &s){
    int n = s.length();
        int i = n - 1;
        while (i >= 0 && s[i] == '1') {
            s[i] = '0';
            i--;
        }
        if (i >= 0) {
            s[i] = '1';
        } else {
            s = "1" + s;
        }
}
    int numSteps(string s) {
      int operations=0;
      int n=s.length();
      while(s.length()>1){
        if(s[s.length()-1]=='1'){
            odd_reducer(s);
        }
        else{
            s.pop_back();
        }
        operations++;
      }
      return operations;  
    }
};