class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int m = n;
        for(int i=1;i<=m/2;i++){
            ans.push_back(-i);
            ans.push_back(i);
        }
        if(n%2==1) ans.push_back(0);
        return ans;
    }
};