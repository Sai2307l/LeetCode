class Solution {
public:
    bool charcheck(char i){
        if(i<'0' || i>'9')return true;
        return false;
    }
    string clearDigits(string s) {
        stack<char> ans;
        for(auto i:s){
            if(charcheck(i)){
                ans.push(i);
            }
            else{
                ans.pop();
            }
        }
        string sol="";
        while(!ans.empty()){
            sol+=ans.top();
            ans.pop();
        }
        reverse(sol.begin(),sol.end());
        return sol;
    }
};