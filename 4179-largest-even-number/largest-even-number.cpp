class Solution {
public:
    string largestEven(string s) {
        int itr=-1;
        for(int i = s.size()-1;i>=0;i--){
            if(s[i]=='2'){
                itr = i;
                break;
            }
        }
        if(itr==-1) return "";
        return s.substr(0,itr+1);
    }
};