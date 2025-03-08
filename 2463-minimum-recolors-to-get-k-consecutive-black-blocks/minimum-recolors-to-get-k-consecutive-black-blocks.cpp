class Solution {
public:
    int minimumRecolors(string blocks, int k) {
       int n=blocks.size();
       
       int window_white=0;
       for(int i=0;i<k;i++){
         if(blocks[i]=='W')window_white++;
       }
       int ans=window_white;
       int j=k;
       int i=0;
         while (j < n) { 
            ans = min(ans, window_white);
            if (blocks[i] == 'W') window_white--;
            if (blocks[j] == 'W') window_white++; 
            j++;
            i++;
        }

        ans = min(ans, window_white);
       return ans; 
    }
};