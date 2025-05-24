class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> sol;
        for(int i=0;i<words.size();i++){
            for(auto j:words[i]){
                if(j==x){
                    sol.push_back(i);
                    break;
                }
                
            }
        }
        return sol;
    }
};