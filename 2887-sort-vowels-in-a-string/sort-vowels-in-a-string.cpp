class Solution {
public:
     bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    string sortVowels(string s) {
         string vowels, consonants;
        for (char ch : s) {
            if (isVowel(ch)) {
                vowels += ch;
            } else {
                consonants += ch;
            }
        }
        
        // Sort the vowels in non-decreasing order based on their ASCII values
        sort(vowels.begin(), vowels.end());
        
        // Create the resulting string by replacing vowels with sorted vowels
        string result = "";
        int vowelIdx = 0;
        for (char ch : s) {
            if (isVowel(ch)) {
                result += vowels[vowelIdx++];
            } else {
                result += ch;
            }
        }
        
        return result;
        
    }
};