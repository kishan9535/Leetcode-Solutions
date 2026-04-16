class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

       int n=nums.size();
       vector<int>ans;
       unordered_map<int,vector<int>>mp;

       for(int i=0;i<n;i++){
        mp[nums[i]].push_back(i);
       }

       for(auto q:queries){

        int ele=nums[q];
          
          vector<int>& vec=mp[ele];
          int res=INT_MAX;
          int size=vec.size();

          if(size==1){
            ans.push_back(-1);
            continue;
          }

          int idx=lower_bound(vec.begin(),vec.end(),q)-vec.begin();

          int l=vec[(idx+1)%size];
          int d=abs(q-l);
          int rev=(n-d);
          res=min({res,d,rev});

          int r=vec[(idx-1+size)%size];
          d=abs(q-r);
          rev=(n-d);
          res=min({res,d,rev});

        ans.push_back(res);

       } 
       return ans;
    }
};