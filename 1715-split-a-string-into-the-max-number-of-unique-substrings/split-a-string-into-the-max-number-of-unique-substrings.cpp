class Solution {
public:
     int n;
    int max_cnt=0;
    void solve(string s,int i,int cnt,set<string>&st){
        if(i>=n && cnt==st.size()){
            max_cnt=max(max_cnt,cnt);
            return;
        }
        // i take k,l as indeces
        for(int j=i;j<n;j++){
            string temp=s.substr(i,j-i+1);
            if(st.find(temp)==st.end()){
            st.insert(temp);
            solve(s,j+1,cnt+1,st);
            st.erase(temp);
            }
        }
            return;
        
    }
    
    int maxUniqueSplit(string s) {
        n=s.length();
        set<string>st;
       solve(s,0,0,st);
        return max_cnt;
    }
};