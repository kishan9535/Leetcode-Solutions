class Solution {
public:
int n,m;
   bool allIndicesMarked(int seconds,vector<int>& changeIndices,vector<int>& nums){
       vector<int>last_Idx(n+1,-1);

       for(int i=0;i<=seconds;i++){
           int idx=changeIndices[i];
           last_Idx[idx]=i+1;
       }
       for(int i=1;i<=n;i++){
           if(last_Idx[i]==-1) return false;
       }

       map<int,int> position_index;

       for(int i=1;i<=n;i++){
           int pos=last_Idx[i];
           position_index[pos]=i;
       }

       int time_passed=0;

       for(auto & [pos, idx]:position_index){

           int req_time=nums[idx-1]+1;
           if(req_time+time_passed>pos) return false;
          time_passed+=req_time;
       }
       return true;


   }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        n=nums.size();
        m=changeIndices.size();

        for(int i=0;i<m;i++){
            if(allIndicesMarked(i,changeIndices,nums)){
                return i+1;
            }
        }

        return -1;
    }
};