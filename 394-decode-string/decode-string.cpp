class Solution {
public:
    string decodeString(string s) {
        string ans;
        stack<int> sI;
        stack<string> sS;

        int num=0;
        
        for(char c:s) {
            if(isdigit(c)) {
                num=num*10+(c-'0');
            } else if(c=='[') {
                sI.push(num);
                sS.push(ans);
                num=0;
                ans="";
            } else if(c==']') {
                int rep=sI.top(); sI.pop();
                string prev=sS.top(); sS.pop();
                string extend="";
                for(int i=0;i<rep;i++) {
                    extend+=ans;
                }
                ans=prev+extend;
            } else {
                ans+=c;
            }
        }
        return ans;
    }
};