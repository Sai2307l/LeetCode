class Solution {
public:
    bool isSubsequence(string s, string t) {
        int itr = 0;
        for(int i=0;i<t.size();i++){
            if(s[itr]==t[i]) itr++;
        }
        return itr==s.size();
    }
};