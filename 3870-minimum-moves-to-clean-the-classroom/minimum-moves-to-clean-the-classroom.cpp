class Solution {
public:

    struct State{
        int row;
        int col;
        int energyLeft;
        int Mask;
    };
    vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};

    using VB=vector<bool>;
    using VVB=vector<VB>;
    using VVVB=vector<VVB>;
    using VVVVB=vector<VVVB>;


    int minMoves(vector<string>& classroom, int energy) {

        int m=classroom.size();
        int n=classroom[0].size();
        int maxeng=energy;

        int litterbit[20][20];
        int littercount=0;
        int sr=0;
        int sc=0;

       for(int r=0;r<m;r++){
        for(int c=0;c<n;c++){
            litterbit[r][c]=-1;

            if(classroom[r][c]=='S'){
                sr=r;
                sc=c;
            }
            else if(classroom[r][c]=='L'){
                litterbit[r][c]=littercount;
                littercount++;
            }
        }
       }

       int allcol=(1<<littercount)-1;
       if(littercount==0)return 0;

       VVVVB seen(m,VVVB(n,VVB(maxeng+1,VB(1<<littercount,false))));

        queue<State> que;
        que.push({sr, sc, maxeng, 0});
        seen[sr][sc][maxeng][0] = true;

        int moves = 0;

        while (!que.empty()) {
            int currSize = que.size();

            while (currSize--) {
                State current = que.front();
                que.pop();

                if (current.Mask == allcol) 
                    return moves;
                if (current.energyLeft == 0) 
                    continue;

                for (auto& di : dir) {
                    int nextRow = current.row + di[0];
                    int nextCol = current.col + di[1];

                    if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n) 
                        continue;

                    char cell = classroom[nextRow][nextCol];
                    if (cell == 'X') 
                        continue;

                    int nextEnergy = current.energyLeft - 1;
                    int nextMask   = current.Mask;

                    if (cell == 'R') {
                        nextEnergy = maxeng;
                    } else if (cell == 'L') {
                        nextMask |= (1 << litterbit[nextRow][nextCol]);
                    }

                    if (!seen[nextRow][nextCol][nextEnergy][nextMask]) {
                        seen[nextRow][nextCol][nextEnergy][nextMask] = true;
                        que.push({nextRow, nextCol, nextEnergy, nextMask});
                    }
                }
            }
            moves++;
        }
       
       return -1;
    }
};