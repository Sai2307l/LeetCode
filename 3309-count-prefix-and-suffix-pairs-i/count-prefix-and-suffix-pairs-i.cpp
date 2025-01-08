class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size(),count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(words[j].size()<words[i].size()) continue;
                string prefix = words[j].substr(0,words[i].size());
                string suffix = words[j].substr((words[j].size()-words[i].size()),words[i].size());
                if(prefix==words[i] && suffix==words[i]) count++;
            }
        }
        return count;
        // return 0;
    }
};