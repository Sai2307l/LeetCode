class Solution {
public:
    bool rotateString(string s, string goal) {
        string ans = goal+goal;
        return goal.size()==s.size() && ans.find(s)!=string::npos;
    }
};