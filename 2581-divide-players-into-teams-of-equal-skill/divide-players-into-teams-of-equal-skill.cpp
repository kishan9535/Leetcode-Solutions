class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
      long long sum=0;
      int n=skill.size();
      vector<int>nums(1001,0);

      for(auto it: skill){
         sum+=it;
         nums[it]++;
      }
      long long teams=n/2;
      long long target=sum/teams;
      if(sum%target!=0)return -1;
 
      long long chemistry=0;
      for(auto it: skill){
        int skil=it;
        int rem_skil=target-skil;
        if(nums[rem_skil]==0)return -1;

        nums[rem_skil]--;
        chemistry+=(skil*rem_skil);
      }
      return chemistry/2;
    }
};