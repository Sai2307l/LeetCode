class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0,i=0;
        string ans="";
        while(i<s.size()){
            if(s[i] == '(')
            {
                if(count > 0) ans.push_back(s[i]); 
                count++;
            }
            else
            {
                count--;
                if(count > 0) ans.push_back(s[i]);
            }
            i++;
        }
        return ans;
    }
};