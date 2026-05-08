class Solution {
public:

vector<bool>isprime;

  void Fillprime(int maxi){

    isprime.resize(maxi+1,true);


    isprime[0]=false;
    isprime[1]=false;

    for(int i=2;i*i<=maxi;i++){

        if(isprime[i]){

            for(int m=i*i;m<=maxi;m+=i){
                isprime[m]=false;
            }
        }
    }
  }

    int minJumps(vector<int>& nums) {

      int n=nums.size();
      int ans=0;
      unordered_map<int,vector<int>>mp;
      int maxi=0;

      for(int i=0;i<n;i++){
        mp[nums[i]].push_back(i);
        maxi=max(maxi,nums[i]);
      }

      Fillprime(maxi);


      queue<int>que;
      que.push(0);
      vector<bool>vis(n,false);
      unordered_set<int>st;
      vis[0]=true;
    
      while(!que.empty()){

        int s=que.size();

        while(s--){
            int f=que.front();
            que.pop();

            if(f==n-1){
                return ans;
            }

            if(f-1>=0 && !vis[f-1]){
                que.push(f-1);
                vis[f-1]=true;
            }

            if(f+1<=n-1 && !vis[f+1]){
                que.push(f+1);
                vis[f+1]=true;
            }

           
           if(!isprime[nums[f]] || st.count(nums[f])){
            continue;
           }

            for(int m=nums[f];m<=maxi;m+=nums[f]){
                if(!mp.contains(m)){
                    continue;
                }

                for(auto &it:mp[m]){
                    if(!vis[it]){
                        que.push(it);
                        vis[it]=true;
                    }
                }
            }
            st.insert(nums[f]);

        }
        ans++;
      }
      return ans;
        
    }
};