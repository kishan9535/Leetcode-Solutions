class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
     int ans=numBottles;
     int empty_Bottles=numBottles;
     while(empty_Bottles>=numExchange){
        empty_Bottles-=numExchange;
        empty_Bottles++;
        numExchange++;
        ans++;
     }
     return ans;   
    }
};