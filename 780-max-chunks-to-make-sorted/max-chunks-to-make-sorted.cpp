class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
     int cnt=0;
     int n=arr.size();
     int maxi=-1;
     for(int i=0;i<n;i++){
        maxi=max(arr[i],maxi);
        if(maxi==i)cnt++;
     }
     return cnt;   
    }
};