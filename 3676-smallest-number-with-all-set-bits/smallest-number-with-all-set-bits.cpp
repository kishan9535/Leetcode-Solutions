class Solution {
public:
    int smallestNumber(int n) {
       int ans=pow(2,ceil(log2(n+1)))-1;
       return ans;
    }
};