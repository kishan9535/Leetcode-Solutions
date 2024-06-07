class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
       int n=nums.size();
       if(n%k)return false;
       map<int,int>mp;
       for(int i=0;i<n;i++){
        mp[nums[i]]++;
       }
       for(auto it=mp.begin();it!=mp.end();){
            if(it->second>0){
                for(int i=0;i<k;i++){
                    if(mp[it->first+i]>0){
                        mp[it->first+i]--;
                    }
                    else{
                        return false;
                    }
                }
            }
            else{
            it++;
            }
        }
       return true;     
    }
};