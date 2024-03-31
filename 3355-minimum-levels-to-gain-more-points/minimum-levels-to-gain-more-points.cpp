class Solution {
public:
    int minimumLevels(vector<int>& possible) {
     int n=possible.size();
     int cnt1=0;
     for(int i=0;i<n;i++){
        if(possible[i]==1)cnt1++;
     }
     int cnt0=n-cnt1;
     int presum=cnt1-cnt0;
     int ans=0;
     int psum=0;
     for(int i=0;i<n-1;i++){
       if(possible[i]==1)psum++;
       else psum--;

       int csum=presum-psum;
        ans=i;
       if(psum>csum)return i+1;
     }
     return -1;   
    }
};