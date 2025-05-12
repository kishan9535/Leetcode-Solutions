class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && j!=k && k!=i && digits[i]!=0 && digits[k]%2==0){
                        int num = digits[i];
                        num= num*10 + digits[j];
                        num= num*10 + digits[k];
                        ans.insert(num); 
                    }
                }
            }
        }
        vector<int> vec(ans.begin(),ans.end());
        return vec;
    }
};