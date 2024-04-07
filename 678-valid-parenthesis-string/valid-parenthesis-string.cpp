class Solution {
public:
 int t[101][101];
   bool solve(int idx, int open_cnt, string s){
    if(idx == s.length() && open_cnt == 0) return true;

       if(t[idx][open_cnt]!=-1)return t[idx][open_cnt];
    bool isValid = false;
    if(s[idx] == '('){
        isValid |= solve(idx+1, open_cnt+1, s);
    }
    else if(s[idx] == '*'){
        isValid |= solve(idx+1, open_cnt+1, s); // treat '*' as '('
        isValid |= solve(idx+1, open_cnt, s); // treat '*' as empty
        if(open_cnt > 0){
            isValid |= solve(idx+1, open_cnt-1, s); // treat '*' as ')'
        }
    }
    else if(s[idx] == ')' && open_cnt > 0){
        isValid |= solve(idx+1, open_cnt-1, s);
    }
    return t[idx][open_cnt]= isValid;
   }
    bool checkValidString(string s) {
        memset(t,-1,sizeof(t));
        return solve(0,0,s);
    }
};
