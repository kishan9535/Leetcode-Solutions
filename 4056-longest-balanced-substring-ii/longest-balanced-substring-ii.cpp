class Solution {
public:

   int max_2cnt(char a ,char b, string s){
    int cnta=0;
    int cntb=0;
    unordered_map<int,int>mp;

    int max_len=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!=a && s[i]!=b){
          mp.clear();
          cnta=0;
          cntb=0;
          continue;
        }

        if(s[i]==a)cnta++;
        if(s[i]==b)cntb++;

        if(cnta==cntb){
            max_len=max(max_len,2*cnta);
        }

        int d=cnta-cntb;

        if(mp.count(d)){
            max_len=max(max_len,i-mp[d]);
        }
        else{
            mp[d]=i;
        }
    }
    return max_len;
   }

    int longestBalanced(string s) {
     int maxi=1;
     int n=s.length();
     unordered_map<string,int>mp;


     int cnt=1;

     for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            cnt++;
        }
        else{
            maxi=max(maxi,cnt);
            cnt=1;
        }
     }
     maxi=max(maxi,cnt);

    maxi= max( max_2cnt('a','b',s) ,maxi);
    maxi= max( max_2cnt('b','c',s) ,maxi);
    maxi= max( max_2cnt('c','a',s) ,maxi);

    int ca=0;
    int cb=0;
    int cc=0;

    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            ca++;
        }
        if(s[i]=='b'){
            cb++;
        }
        if(s[i]=='c'){
            cc++;
        }

        if(ca==cb && ca==cc){
            maxi=max(maxi,3*ca);
        }

        int dab=ca-cb;
        int dac=ca-cc;

        string key=to_string(dab)+"_"+to_string(dac);

        if(mp.count(key)){
            maxi=max(maxi,(i-mp[key]));
        }
        else{
            mp[key]=i;
        }
        
    }
    return maxi;

    }
};