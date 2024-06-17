class Solution {
public:
    bool judgeSquareSum(int c) {
      vector<int>a;
      
     if(c==2||c==1)return true;
     
      long i=0;
      long j=sqrt(c);
      while(i<=j)
      {
          long t=(i*i)+(j*j);

          if(t==c)return true;
          else if(t>c)j--;
          else
          i++;

      }  
      return false;
    }
};