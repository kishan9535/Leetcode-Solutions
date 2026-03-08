class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
       string ans="";
       int n=nums.size();

       for(int i=0;i<n;i++){
        char ch=nums[i][i];

        ans+=(ch=='0'?'1':'0');
       }
       return ans;
    }
};