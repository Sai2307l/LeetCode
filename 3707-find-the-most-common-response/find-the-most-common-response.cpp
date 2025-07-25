class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {

        map<string,int> res;

        for(auto a: responses){
            map<string, int> demo;
            for(int i = 0; i < a.size(); i++) {
                demo[a[i]] = 1;  // to remove duplicates within the same list
            }

            for(auto x: demo) {
                res[x.first]++;  // count unique responses across all lists
            }
        }

        int mx = 0;
        string temp;
        for(auto a: res) {
            if(a.second > mx) {
                temp = a.first;
                mx = a.second;
            }
        }
        return temp;
    }
};