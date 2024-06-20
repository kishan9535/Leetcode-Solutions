class Solution {
public:

    bool Can_Place_balls(vector<int>& position,int mid , int m){
        int cnt=0;
        int prev=position[0];
        cnt++;

        for(int i=1;i<position.size()&& cnt < m;i++){
            int curr=position[i];
            
            if(curr-prev>=mid){
                cnt++;
                prev=curr;
            }
        }
        return cnt>=m;
    }
    int maxDistance(vector<int>& position, int m) {
     
     int n=position.size();
     sort(position.begin(),position.end());
     int l=1;
     int r=position[n-1]-l;
     int ans=0;
     int mid;

     while(l<=r){

         mid=l+(r-l)/2;
        if(Can_Place_balls(position,mid,m)){
            ans=mid;
            l=mid+1 ; 
        }
        else{
            r=mid-1;
        }
     }
     return ans;
    }
};