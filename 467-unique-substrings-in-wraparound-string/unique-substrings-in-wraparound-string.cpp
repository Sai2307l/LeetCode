class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int ans = 0;
        int pre = 1;
        vector<int> chars(26,0);
        chars[s[0]-'a'] = 1;
        for(int i=1;i<s.size();i++){
            if(s[i]-s[i-1]==1 || s[i] - s[i-1] == -25){
                pre += 1;
            }else{
                pre = 1;
            }
            chars[s[i]-'a'] = max(pre,chars[s[i]-'a']);
        }
        for(auto i:chars) ans+=i;
        return ans;
    }
};