class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> st;
        for(auto i:dictionary){
            st.insert(i);
        }
        string ans="";
        int n=sentence.length();
        int i=0,j=0;
        while(i<n){
            while(j<n && sentence[j]!=' '){
                j++;
            }
            bool flag=true;
            for(int k=i;k<j;k++){
                string s=sentence.substr(i,k-i+1);
                if(st.find(s)!=st.end()){
                    ans+=s;
                    ans+=" ";
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                string ss=sentence.substr(i,j-i);
                ans+=ss;
                ans+=" ";
            }
            i=j+1; // Move to the next word
            j=i;
        }
        ans.pop_back();// Remove the trailing space
        return ans;    
    }
};
