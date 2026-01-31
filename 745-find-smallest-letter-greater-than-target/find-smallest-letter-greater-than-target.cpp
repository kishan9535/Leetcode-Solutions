class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int s=letters.size();
        for(int i=0;i<s;i++)
        {
            if(letters[i]>target) return letters[i];
        }
        return letters[0];
    }
};