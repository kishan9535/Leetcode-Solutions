class Solution {
public:
    int bitwiseComplement(int n) {
       int ans=0;
       int i=0;
       if(n==0)return 1;
       while(n>0){
        int l=n%2;
        ans= ans+(pow(2,i)*!l);
        n/=2;
        i++;
       }
       return ans;
    }
};