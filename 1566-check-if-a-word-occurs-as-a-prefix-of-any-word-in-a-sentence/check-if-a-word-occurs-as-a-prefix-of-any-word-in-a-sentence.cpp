class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
      vector<string>ans;
      int n=sentence.size();
      int s=searchWord.size();
      for(int i=0;i<n;i++){
        string temp="";
        while(sentence[i]!=' ' && i<n){
            temp+=sentence[i];
            i++;
        }
        cout<<temp<<endl;
        ans.push_back(temp);
    }
    for(int i=0;i<ans.size();i++){
        string t=ans[i];
        if(t.substr(0, s) == searchWord)return i+1;
    }
    return -1;  
    }
};