class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n=asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        long long ans=mass;

        for(int i=0;i<n;i++){
            if(ans>=asteroids[i]){
                ans+=asteroids[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};