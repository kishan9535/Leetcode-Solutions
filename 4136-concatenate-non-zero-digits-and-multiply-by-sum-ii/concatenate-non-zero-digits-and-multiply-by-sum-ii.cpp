class Solution {
public:
     
     typedef long long ll;
     int Mod=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        
        int n=s.length();
        vector<ll>digitcnt(n,0);
        vector<ll>number(n,0);
        vector<int>nonzerocnt(n,0);
        vector<ll>powcnt(n+1,0);

        powcnt[0]=1;

        for(int i=1;i<=n;i++){
            powcnt[i]=(powcnt[i-1]*10)%Mod;
        }

        nonzerocnt[0]=(s[0]!='0')?1:0;
        number[0]=(s[0]-'0');
        digitcnt[0]=number[0];

        for(int i=1;i<n;i++){
            int d=s[i]-'0';

            nonzerocnt[i]=nonzerocnt[i-1]+((d!=0)?1:0);
            digitcnt[i]=digitcnt[i-1]+d;

            if(d!=0){
                number[i]=((number[i-1]*10)+d)%Mod;
            }
            else{
                number[i]=number[i-1];
            }
        }
        int q=queries.size();
        vector<int>ans(q);

        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];

            ll sum=digitcnt[r]-((l==0)?0:digitcnt[l-1]);
            int nb=((l==0)?0:number[l-1]);
            int k=nonzerocnt[r]-((l==0)?0:nonzerocnt[l-1]);
            ll x=(number[r]-(nb*powcnt[k]%Mod)+Mod)%Mod;

            ans[i]=(int)((sum%Mod *x)%Mod);

        }

        return ans;  
                }
};