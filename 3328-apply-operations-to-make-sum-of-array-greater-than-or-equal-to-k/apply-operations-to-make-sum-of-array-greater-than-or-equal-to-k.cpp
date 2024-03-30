class Solution {
public:
    int minOperations(int k) {
     if(k==1)return 0;
     int min_operations=INT_MAX;
     for(int i=0;i<k;i++){
        int curValue=i+1;
        int div=(k+curValue-1)/curValue-1;

        min_operations=min(min_operations,i+div);
     }
     return min_operations;   
    }
};