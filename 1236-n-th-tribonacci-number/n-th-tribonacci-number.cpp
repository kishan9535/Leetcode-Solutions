class Solution {
public:
    int tribonacci(int n) {
        if(n==0)return 0;
        int a=0,b=1,c=1,d;
        for(int i=3;i<=n;i++)
        {
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return c;
    }
};