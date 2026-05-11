class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {

        int n=nums.size();
        vector<int>ans;

        for(int i=0;i<n;i++){
            int num=nums[i];
            vector<int>tmp;

              while(num){
                int l=num%10;
                tmp.push_back(l);
                num/=10;
            }
            reverse(tmp.begin(),tmp.end());
            for(int j=0;j<tmp.size();j++){
                ans.push_back(tmp[j]);
            }
        }
        return ans;  
    }
};