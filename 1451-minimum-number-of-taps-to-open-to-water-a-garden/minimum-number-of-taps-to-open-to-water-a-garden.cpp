class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
      vector<int> startEnd(n+1, 0);
        
        for(int i = 0; i<ranges.size(); i++) {
            
         int start = max(0, i - ranges[i]);
            int end   = min(n, i + ranges[i]);
            
            startEnd[start] = max(startEnd[start], end);
            
        }
        
        int taps     = 0;
        int currEnd  = 0;
        int maxEnd   = 0;
        
        for(int i = 0; i<n+1; i++) {
            
            if(i > maxEnd)
                return -1;
            
            if(i > currEnd) {
                taps++;
                currEnd = maxEnd;
            }
            
            maxEnd = max(maxEnd, startEnd[i]);
            
        }
        
        return taps;      
    }
};