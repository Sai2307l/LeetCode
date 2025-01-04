class Solution {
public:
    int countPalindromicSubsequence(string s) {
        bitset<26> letters;
        int sol=0;
        for(int i=0;i<26;i++){
            int l = s.find('a'+i);
            if(l==string::npos) continue;
            int r = s.find_last_of('a'+i);
            for(int i=l+1;i<r;i++){
                letters.set(s[i]-'a');
                if(letters.count()==26) break;
            }
            sol+=letters.count();
            letters.reset();
        }
        return sol;
    }
};