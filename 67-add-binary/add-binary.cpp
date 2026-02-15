class Solution {
public:
    string addBinary(string a, string b) {
     
     int m=a.length()-1;
     int n=b.length()-1;

     string ans="";

     int sum=0;
     int carry=0;

     while(n>=0||m>=0){
        sum=carry;

        if(n>=0){
            sum+=b[n]-'0';
            n--;
        }
        if(m>=0){
            sum+=a[m]-'0';
            m--;
        }

        ans+=((sum%2==0)?'0':'1');
        carry= (sum>1)?1:0;
     }
     if(carry){
        ans+='1';
     }
     reverse(ans.begin(),ans.end());
     return ans;
     
    }
};