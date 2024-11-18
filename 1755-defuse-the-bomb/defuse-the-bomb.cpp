class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
      int n=code.size();
      vector<int>ans(n,0);
      if(k==0)return ans;
      int i,j;
      int sum=0;
       if(k>0){
        for(j=1;j<=k;j++){
            sum+=code[j];
        }
        cout<<sum<<endl;
        i=1,j=k;
       }
      else{
        for(j=(n-abs(k));j<n;j++){
            sum+=code[j%n];
        }
        i=(n-abs(k));
        j=n-1;
      }
      cout<<i<<j;
      for(int h=0;h<n;h++){
        ans[h]=sum;
        sum-=code[i%n];
        i++;
        sum+=code[(j+1)%n];
        j++;
        cout<<i<<" "<<j<<endl;
      }
       return ans;
    }
};