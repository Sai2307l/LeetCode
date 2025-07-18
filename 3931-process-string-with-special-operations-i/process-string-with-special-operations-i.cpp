class Solution {
public:
    string processStr(string s) {
        string sol="";
        int i=0;
        while(i<s.size()){
            if(s[i]=='*'){
                if( sol.empty()==false )sol.pop_back(); 
            }
            else if(s[i]=='#'){
                sol.append(sol);
            }
            else if(s[i]=='%'){
                reverse(sol.begin(),sol.end());
            }
            else{
                sol+=s[i];
            }
            i++;
        }
        return sol;
    }
};