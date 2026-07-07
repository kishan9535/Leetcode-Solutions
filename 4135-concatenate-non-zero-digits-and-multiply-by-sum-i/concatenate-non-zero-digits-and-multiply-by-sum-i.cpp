class Solution {
public:
    long long sumAndMultiply(int n){

        long long ans=0;
        int sum=0;
        string num="";

        if(n==0)return 0;

        while(n){
            int d=n%10;
            if(d){
                num+=('0'+d);
                sum+=d;
            }
            n/=10;
        }

        reverse(num.begin(),num.end());
        ans=stoll(num);
        ans=(ans*sum);

        return ans;
    }
};