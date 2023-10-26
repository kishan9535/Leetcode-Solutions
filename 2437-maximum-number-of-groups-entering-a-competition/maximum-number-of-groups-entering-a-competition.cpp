class Solution {
public:
    int maximumGroups(vector<int>& grades) {
       int x=1;
       int n=grades.size();
       while(x*(x+1)/2 <=n)x++;
       return --x;
    }
};