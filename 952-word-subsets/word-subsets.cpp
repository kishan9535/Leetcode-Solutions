class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
      vector<int>key(26,0);
      vector<string>ans;
      for(auto it: words2){
        vector<int>temp(26,0);
        for(auto i:it){
            temp[i-'a']++;
        }
        for(int i=0;i<26;i++){
            key[i]=max(key[i],temp[i]);
        }
      }
    //    for(auto it: key){
    //     cout<< it<<endl;
    //    }
     for(auto it: words1){
        vector<int>tmp(26,0);
        for(auto i:it){
            tmp[i-'a']++;
        }
        bool flag=true;
        for(int i=0;i<26;i++){
            if(key[i]>tmp[i]){
                flag=false;
                break;
            }
        }
        if(flag) ans.push_back(it);
     }

       return ans;
    }
};