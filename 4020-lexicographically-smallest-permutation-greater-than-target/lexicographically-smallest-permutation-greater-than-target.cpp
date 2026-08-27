class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int freq[26] = {};

        for(char c : s)
            freq[c - 'a']++;

        string ans;
        bool fl = false;

        for(char c : target) {
            int x = c - 'a';

            if(freq[x] > 0) {
                ans += c;
                freq[x]--;
            }
            else {
                for(int right = x + 1; right < 26; right++) {
                    if(freq[right] > 0) {
                        ans += char(right + 'a');
                        freq[right]--;
                        fl = true;
                        break;
                    }
                }
                break;
            }
        }

        if(fl) {
            for(int i = 0; i < 26; i++)
                while(freq[i]--)
                    ans += char(i + 'a');

            return ans;
        }

        for(int i = ans.size() - 1; i >= 0; i--) {
            freq[ans[i] - 'a']++;

            int x = ans[i] - 'a';

            for(int right = x + 1; right < 26; right++) {
                if(freq[right] == 0)
                    continue;

                string res = ans.substr(0, i);
                res += char(right + 'a');
                freq[right]--;

                for(int c = 0; c < 26; c++){
                    while(freq[c]--)
                        res += char(c + 'a');
                }

                return res;
            }
        }

        return "";
    }
};