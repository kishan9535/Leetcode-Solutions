class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n=arr.size();
        vector<bool>vis(n,false);
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

        int steps=0;
        queue<int>que;

        que.push(0);

        while(!que.empty()){

            int s=que.size();

            while(s--){
                int cur=que.front();
                que.pop();

                int l=cur-1;
                int r=cur+1;

                if(cur==n-1){
                    return steps;
                }

                if(l>=0 &&!vis[l]){
                    que.push(l);
                    vis[l]=true;
                }

                if(r<=n-1 && !vis[r]){
                    que.push(r);
                    vis[r]=true;
                }

                for(auto &it:mp[arr[cur]]){
                    if(!vis[it]){
                        que.push(it);
                        vis[it]=true;
                    }
                }
                mp.erase(arr[cur]);
            }
            steps++;
        }

        return steps;   
    }
};