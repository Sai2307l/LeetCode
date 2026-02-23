class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<=k) return false;
        set<string> nums;
        string substr = s.substr(0,k);
        nums.insert(substr);
        for(int i=k;i<s.size();i++){
            substr = substr.substr(1) + s[i];
            nums.insert(substr);
        }
        if(nums.size()==pow(2,k))return true;
        else return false;
    }
};