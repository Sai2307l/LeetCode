class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();
        map<char,int> freq_s,freq_t;
        for(auto i:s)freq_s[i]++;
        for(auto i:t)freq_t[i]++;
        for(char i='a' ; i<='z';i++){
            if(freq_s[i]!=freq_t[i]) return i;
        }
        return 'a';
    }
};