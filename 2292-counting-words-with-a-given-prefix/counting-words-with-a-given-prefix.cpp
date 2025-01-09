class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(auto i:words){
            if(i.size()<pref.size()) continue;
            if(i.substr(0,pref.size())==pref) count++;
        }
        return count;
    }
};