class Solution {
public:
    int totalMoney(int n) {
        int terms=n/7;
        int first=28;
        int last= 28 +(terms-1)*7;
        int AP_Sum= terms* (first+last)/2;
        int result=AP_Sum;
        int start_money= 1+ terms;
        for(int day=1;day<=(n%7);day++){
            result+=start_money;
            start_money++;
        }
        return result;
    }
};