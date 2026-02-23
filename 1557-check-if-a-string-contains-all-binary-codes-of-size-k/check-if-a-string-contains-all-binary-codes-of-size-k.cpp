class Solution {
public:
    int conv(string s, int k){
        int val = 0;
        for(int i=k-1;i>=0;i--){
            val+= (s[i]-'0') * pow(2,(k-1) - i);
        }
        return val;
    }
    bool hasAllCodes(string s, int k) {
        if(s.size()<=k) return false;
        set<int> nums;
        string substr = s.substr(0,k);
        int num = conv(substr,k);
        nums.insert(num);
        for(int i=k;i<s.size();i++){
            substr = substr.substr(1) + s[i];
            num = conv(substr,k);
            nums.insert(num);
        }
        if(nums.size()==pow(2,k))return true;
        else return false;
    }
};