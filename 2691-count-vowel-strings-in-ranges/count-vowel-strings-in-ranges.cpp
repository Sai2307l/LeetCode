class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans,sol;
        ans=is_k(words);
        for(auto i:queries){
            int l=i[0]-1;
            int r=i[1];
            sol.push_back(l==-1?ans[r]:ans[r]-ans[l]);
        }
        return sol;
    }

private:
    vector<int> is_k(vector<string>& words){
        vector<int> is_ok;
        map<char,bool> comp={{'a',true},{'e',true},{'i',true},{'o',true},{'u',true}};
        int val=0;
        for(auto i:words){
            bool left= comp[i[0]];
            bool right= comp[i[i.size()-1]];
            if(left && right){
                val++;
                is_ok.push_back(val);
            }
            else is_ok.push_back(val);
        }
        for(auto i:is_ok) cout<<i<<" ";
        return is_ok;
    }

};