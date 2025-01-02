class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans,sol;
        ans=is_k(words);
        for(auto i:queries){
            sol.push_back(i[0]-1==-1?ans[i[1]]:ans[i[1]]-ans[i[0]-1]);
        }
        return sol;
    }

private:
    vector<int> is_k(vector<string>& words){
        vector<int> is_ok;
        map<char,bool> comp={{'a',true},{'e',true},{'i',true},{'o',true},{'u',true}};
        int val=0;
        for(auto i:words){
            if(comp[i[0]] && comp[i[i.size()-1]]){
                val++;
                is_ok.push_back(val);
            }
            else is_ok.push_back(val);
        }
        return is_ok;
    }

};