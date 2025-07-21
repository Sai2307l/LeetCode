class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()==1 || s.size()==2) return s;
        string ans="";
        ans+=s[0];
        int count=0;
        for(int i=1;i<s.size();i++){
            if(s[i-1]==s[i] && count<1){
                ans+=s[i];
                count++;
            }
            else if(s[i-1]!=s[i]){
                ans+=s[i];
                count=0;
            }
        }
        return ans;
    }
};