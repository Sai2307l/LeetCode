class Solution {
public:
    vector<string> partitionString(string s) {
        map<string,int> freq;
        vector<string> sol;
        string a="";
        for(int i=0;i<s.size();i++){
            a+=s[i];
            if(freq.find(a)==freq.end()){
                freq[a] = 1;
                sol.push_back(a);
                a.clear();
            }
        }
        return sol;
    }
};