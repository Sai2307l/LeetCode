class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> freq(26,0);
        for(auto& i:s) freq[i-'a']++;
        int odd=0,count=0;
        for(int i=0;i<26;i++){
            if(freq[i]==0)continue;
            count++;
            if(freq[i]%2!=0) odd++;
        }
        if(odd<=k && s.size()>=k)return true;
        else return false;
    }
};