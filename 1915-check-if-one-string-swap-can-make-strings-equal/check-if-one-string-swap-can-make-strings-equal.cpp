class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return true;
        if(s1.size()!=s2.size()) return false;
        int n=s1.size();
        int i=0,j=n-1;
        while(i<n&&s1[i]==s2[i])
        {
            i++;
        }
        while(j>0&&s1[j]==s2[j])
        {
            j--;
        }
        swap(s1[i],s1[j]);
        if(s1==s2)return true;
        return false;
    }
};