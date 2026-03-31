class Solution {
public:

     bool Same(string &word,string & str2,int i, int m){
        for(int j=0;j<m;j++){
            if(word[i]!=str2[j]){
                return false;
            }
            i++;
        }
        return true;
     }

    string generateString(string str1, string str2) {

     int n=str1.length();
     int m=str2.length();

     int N=m+n-1;
     string ans(N,'$');

     vector<bool>change(N,false);

     for(int i=0;i<n;i++){
        if(str1[i]=='T'){
            int i_=i;

            for(int j=0;j<m;j++){
                if(ans[i_]!='$' && ans[i_]!=str2[j]){
                    return "";
                }
                ans[i_]=str2[j];
                i_++;
            }
        }
     }

     for(int i=0;i<N;i++){
        if(ans[i]=='$'){
            ans[i]='a';
            change[i]=true;
        }
     }

     for(int i=0;i<n;i++){
        if(str1[i]=='F'){
            if(Same(ans,str2,i,m)){
                bool ch=false;
          for(int k=i+m-1;k>=i;k--){
            if(change[k]==true){
                ans[k]='b';
                ch=true;
                break;
            }
          }
             if(ch==false){
                return "";
             }
            }
        }
     }

     return ans;
    }
};