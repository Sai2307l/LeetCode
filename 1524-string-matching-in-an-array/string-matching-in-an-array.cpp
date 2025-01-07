class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> sol;
        for(auto &i:words){
            for(auto &j:words){
                if(i!=j && i.size()>=j.size() && i.find(j)!=string::npos){
                    sol.insert(j);
                }
            }
        }
        vector<string> ans;
        for(auto i:sol)ans.push_back(i);
        return ans;
    }
};