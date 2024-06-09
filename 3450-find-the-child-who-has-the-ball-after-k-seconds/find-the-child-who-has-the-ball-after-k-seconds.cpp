class Solution {
public:
    int numberOfChild(int n, int k) {
       int position=0;
       int directions=1;

       for(int i=0;i<k;i++){
         position+=directions;

         if(position==n-1||position==0){
            directions=-directions;
         }
       }
       return position; 
    }
};