class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
       int max_row=1;
     int max_col=1;

     sort(hBars.begin(),hBars.end()); 
     sort(vBars.begin(),vBars.end());
       int cnt=1;
     for(int i=0;i<vBars.size()-1;i++){
       if(vBars[i+1]==vBars[i]+1){
          cnt++;
          max_row=max(max_row,cnt);
       }
       else{
        cnt=1;
       }
     }
       cnt=1;
     for(int i=0;i<hBars.size()-1;i++){
       if(hBars[i+1]==hBars[i]+1){
          cnt++;
          max_col=max(max_col,cnt);
       }
       else{
        
        cnt=1;
       }
     }

     
     int area= min(max_row,max_col)+1;
   
     

     return (area*area);
    }
};