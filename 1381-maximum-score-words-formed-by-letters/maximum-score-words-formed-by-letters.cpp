class Solution {
public:
     int ans=INT_MIN;
     int n;
      void solve(int idx,vector<string>& words, int cur_ans,vector<int>&freq,vector<int>& score){
        if(idx>=n){
            ans=max(ans,cur_ans);
            return;
        }
        int i=0;
        int m=words[idx].size();
        vector<int>temp;
        temp=freq;
        int temp_ans=0;
        while(i<m){
            char ch=words[idx][i];
            temp[ch-'a']--;
            temp_ans+=score[ch-'a'];
            if(temp[ch-'a']<0){
                break;
            }
            i++;
        }
        if(i==m){
            solve(idx+1,words,cur_ans+temp_ans,temp,score);
        }
        solve(idx+1,words,cur_ans,freq,score);
      }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n=words.size();
        vector<int>freq(26,0);
        for(auto i:letters){
            freq[i-'a']++;
        }
        solve(0,words,0,freq,score);
        return ans;
    }
};