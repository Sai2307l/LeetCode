class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        map<char,pair<int,int>> first_last;
        for(int i=0;i<n;i++){
            if(first_last.find(s[i])==first_last.end()){
                first_last[s[i]].first=i;
            }
            first_last[s[i]].second=i;
        }
        int sol=0;
        set<char> unique;
        for(auto [letter,positions]:first_last){
            int left = positions.first;
            int right = positions.second;
            if(right-left<=1) continue;            
            for(int i=left+1;i<right;i++){
                unique.insert(s[i]);
            }
            sol+=unique.size();
            unique.clear();
        }
        return sol;
    }
};