class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long>ms;
        for(auto i:nums){
            ms.insert(i);
        }
        int ans=0;
        while(ms.size()>1){
           long long v1=*ms.begin();
           ms.erase(ms.begin());
           if(v1>=k)break;
           long long v2=*ms.begin();
           ms.erase(ms.begin());
           long long tem=(v1*2)+v2;
           ms.insert(tem);
           ans++;
        }
        return ans;
    }
};