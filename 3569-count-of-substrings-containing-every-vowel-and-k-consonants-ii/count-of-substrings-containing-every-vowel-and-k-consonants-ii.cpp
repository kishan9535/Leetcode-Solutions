class Solution {
public:
    bool is_vowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        if (n == 0 || k > n) return 0;

        unordered_map<char, int> mp;
        vector<int> next_cons(n);
        int last_cons_idx = n;

        for (int i = n - 1; i >= 0; i--) {
            next_cons[i] = last_cons_idx;
            if (!is_vowel(word[i])) {
                last_cons_idx = i;
            }
        }

        int i = 0, j = 0, count_k = 0;
        long long ans = 0;

        while (j < n) {
            if (is_vowel(word[j])) {
                mp[word[j]]++;
            } else {
                count_k++;
            }

            while (count_k > k) {
                if (is_vowel(word[i])) {
                    if (--mp[word[i]] == 0) {
                        mp.erase(word[i]);
                    }
                } else {
                    count_k--;
                }
                i++;
            }

            while (i < n && mp.size() == 5 && count_k == k) {  
                int idx = next_cons[j];  
                ans += idx - j;  
                char ch = word[i];
                if (is_vowel(ch)) {
                    mp[ch]--;
                    if (mp[ch] == 0) {
                        mp.erase(ch);
                    }
                } else {
                    count_k--;
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};
