class Solution {
public:

   bool solve(int num){

    bool flag=false;

    while(num!=0){
        int d=num%10;

        if(d==3||d==4||d==7)return false;
        if(d==2||d==5||d==6||d==9)flag=true;

        num/=10;
    }
  return flag;
    
   }

    int rotatedDigits(int n) {
        
        int ans=0;
    
     for(int i=1;i<=n;i++){
        if(solve(i))ans++;
     }

     return ans;

    }
};