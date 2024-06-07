class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
       int n=nums.size();
       if(n%k)return false;
       map<int,int>mp;
       for(int i=0;i<n;i++){
        mp[nums[i]]++;
       }
       while(!mp.empty()){
            int minElement = mp.begin()->first;
            for(int i=0;i<k;i++){
                if(mp.find(minElement+i) == mp.end()){
                    return false;
                }
                mp[minElement+i]--;
                if(mp[minElement+i] == 0){
                    mp.erase(minElement+i);
                }
            }
        }
       return true;     
    }
};