class Solution {
public:
    int hammingWeight(uint32_t n) {
      int cnt=__builtin_popcount(n);
      return cnt;  
    }
};