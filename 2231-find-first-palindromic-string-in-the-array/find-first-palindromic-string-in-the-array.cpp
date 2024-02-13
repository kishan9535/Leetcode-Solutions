class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string t="";
        for(int i=0;i<words.size();i++)
        {
            /*t=words[i];
            reverse(t.begin(),t.end());
            if(t==words[i]) return words[i];
             */
             if(isPalindrome(words[i]))return words[i];
        }
        return "";
    }
    public:
    bool isPalindrome(string s)
    {
        int st=0;
        int end=s.size()-1;
        while(st<end)
        {
         if(s[st]==s[end])
         {
             st++,end--;
         }
         else return false;

        }
        return true;
    }
};