class Solution {
public:

typedef long long ll;



   ll solve(int r,int f,vector<int>&robot,vector<int>&pos,vector<vector<ll>>&t){
      if(r>=robot.size())return 0;
      if(f>=pos.size())return 1e12;

      if(t[r][r]!=-1)return t[r][f];

      ll take=abs(robot[r]-pos[f])+solve(r+1,f+1,robot,pos,t);
      ll skip=solve(r,f+1,robot,pos,t);


      return t[r][f]= min(take,skip);
   }
  
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

      sort(robot.begin(),robot.end());
      sort(factory.begin(),factory.end());
      vector<int>pos;

      for(int i=0;i<factory.size();i++){
        int val=factory[i][0];
        int cnt=factory[i][1];

        for(int j=0;j<cnt;j++){
            pos.push_back(val);
        }
      }
       int m=robot.size();
       int n=pos.size();
       vector<vector<ll>>t(m+1,vector<ll>(n+1,-1));
      return solve(0,0,robot,pos,t); 
    }
};