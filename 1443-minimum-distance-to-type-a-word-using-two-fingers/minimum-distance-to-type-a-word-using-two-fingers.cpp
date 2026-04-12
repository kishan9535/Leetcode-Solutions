class Solution {
public:
    
     int t[301][27][27];
     pair<int,int>getcordinates(int idx){
        return{idx/6,idx%6};
     }

     int getDistances(int p1,int p2){
        
        auto[x1,x2]=getcordinates(p1);
        auto[y1,y2]=getcordinates(p2);

        return (abs(x1-y1)+abs(x2-y2));
     }

    int solve(string word, int idx, int f1, int f2){
        if(idx>=word.length())return 0;

        int cur=word[idx]-'A';

        if(t[idx][f1][f2]!=-1)return t[idx][f1][f2];

        if(f1==26 && f2==26){
            return t[idx][f1][f2]= solve(word,idx+1,cur,f2);
        }

        if(f2==26){
            int mf1=getDistances(cur,f1)+solve(word,idx+1,cur,f2);
            int mf2=solve(word,idx+1,f1,cur);

            return t[idx][f1][f2]= min(mf1,mf2);
        }

        int mf1=getDistances(f1,cur)+solve(word,idx+1,cur,f2);
        int mf2=getDistances(f2,cur)+solve(word,idx+1,f1,cur);

        return t[idx][f1][f2]= min(mf1,mf2);
    }

    int minimumDistance(string word) {
     memset(t,-1,sizeof(t));
     return solve(word,0,26,26);   
    }
};