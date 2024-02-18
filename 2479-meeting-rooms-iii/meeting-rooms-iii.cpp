class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
      int m=meetings.size();
      sort(meetings.begin(),meetings.end());
      vector<long long>latAvailableAt(n,0);
      vector<int>roomsUsed_cnt(n,0);
      for(auto meet:meetings){
         int start=meet[0];
         int end=meet[1];
         int duration=end-start;
         bool found=false;
         
         long long earlyEnd_Time=LLONG_MAX;
         int earlyend_Room=0;

         for(int r=0;r<n;r++){

             if(latAvailableAt[r]<=start){
                 latAvailableAt[r]=end;
                 roomsUsed_cnt[r]++;
                 found=true;
                 break;
             }

             if(latAvailableAt[r]<earlyEnd_Time){
                earlyEnd_Time=latAvailableAt[r];
                earlyend_Room=r;

             }
         }
         if(!found){
            latAvailableAt[earlyend_Room]+=duration;
             roomsUsed_cnt[earlyend_Room]++;
         }
      }
      int res_Room=-1;
      int maxi=0;
      for(int i=0;i<n;i++){
          if(roomsUsed_cnt[i]>maxi){
              maxi=roomsUsed_cnt[i];
              res_Room=i;
          }
      }
      return res_Room;

    }
};