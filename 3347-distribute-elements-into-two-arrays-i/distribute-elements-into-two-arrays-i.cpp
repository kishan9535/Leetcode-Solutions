class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        int n=nums.size();
        vector<int>ar1;
        vector<int>ar2;

        ar1.push_back(nums[0]);
        ar2.push_back(nums[1]);

        for(int i=2;i<n;i++){

            if(ar1.back()>ar2.back()){
                ar1.push_back(nums[i]);
            }
            else{
                ar2.push_back(nums[i]);
            }
        }

        for(auto &it:ar2){
            ar1.push_back(it);
        }
      return ar1;

    }
};