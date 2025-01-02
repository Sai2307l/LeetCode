class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> is_ok,sol;
        map<char,bool> comp={{'a',true},{'e',true},{'i',true},{'o',true},{'u',true}};
        int val=0;
        for(auto i:words){
            if(comp[i[0]] && comp[i[i.size()-1]]){
                val++;
                is_ok.push_back(val);
            }
            else is_ok.push_back(val);
        }
        for(auto i:queries){
            sol.push_back(i[0]-1==-1?is_ok[i[1]]:is_ok[i[1]]-is_ok[i[0]-1]);
        }
        return sol;
    }
};