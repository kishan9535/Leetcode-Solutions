class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

      int Total_bottles=0;
      while(numBottles>=numExchange){
          Total_bottles+=numExchange;
          numBottles-=numExchange;
          numBottles++;
      }
      return Total_bottles+numBottles;  
    }
};