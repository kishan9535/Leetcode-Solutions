class Solution {
public:
    int Mod=1e9+7;
    int t[5001][13];
    string pos[12] ={"RYR","RYG","RGR","RGY","YRY","YRG","YGR","YGY","GRY","GRG","GYR","GYG"};

    int solve(int row,int idx){
        if(row==0)return 1;
         if(t[row][idx]!=-1)return t[row][idx];
        string prev= pos[idx];

        int ans=0;

        for(int i=0;i<12;i++){
          if(idx==i)continue;
          bool flag=false;
          string cur=pos[i];
          for(int j=0;j<3;j++){
            if(prev[j]==cur[j]){
                flag=true;
                break;
            }
          }
            if(!flag){
             ans= (ans+solve(row-1,i))%Mod;
            }
          }
        
        return t[row][idx]=ans;
    }
    int numOfWays(int n) {
        int ans=0;
       memset(t,-1,sizeof(t));
        for(int i=0;i<12;i++){
            ans= (ans+solve(n-1,i))%Mod;
        }
        return ans;
    }
};