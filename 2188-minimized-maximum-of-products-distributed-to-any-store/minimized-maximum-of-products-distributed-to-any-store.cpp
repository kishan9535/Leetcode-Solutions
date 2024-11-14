class Solution {
public:
    bool is_Possible(int n,vector<int>& quantities,int key){
       int count=0;
       for(auto it: quantities){
           int req = (it + key - 1) / key;//int req=ceil(it/key);
        count+=req;
       }  
       return n>=count;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
      int ans=INT_MAX;
      int l=1;
      int r=1e5;

      while(l<=r){
        int mid=l+(r-l)/2;

        if(is_Possible(n,quantities,mid)){
            ans=min(ans,mid);
            r=mid-1;
        }
        else{
            l=mid+1;
        }
      }
      return ans;  
    }
};