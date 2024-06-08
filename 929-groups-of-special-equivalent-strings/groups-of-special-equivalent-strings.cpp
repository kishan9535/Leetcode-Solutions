class Solution {
public:
 string valid_string(string s){
    int n=s.length();
    string odd,even;
    for(int i=0;i<n;i++){
        if(i%2==0){
            even+=s[i];
        }
        else{
            odd+=s[i];
        }
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    
        string result(n, ' ');
        int j = 0, k = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                result[i] = even[j++];
            } else {
                result[i] = odd[k++];
            }
        }
        return result;
 }
    int numSpecialEquivGroups(vector<string>& words) {
      unordered_map<string,int>mp;
      int n=words.size();
      for(int i=0;i<n;i++){
         string temp =valid_string(words[i]);
         mp[temp]++;
      }
      int ans=0;
      for(auto i: mp){
        ans++;
      }
      return ans;  
    }
};