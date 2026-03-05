class Solution {
public:
    int minOperations(string s) {
        int ans,sols = 0;
        for(int i=0;i<s.size();i++){
            if(i%2==0 && s[i]=='1') sols++;
            if(i%2==1 && s[i]=='0') sols++;
        }
        ans = sols;
        sols=0;
        for(int i=0;i<s.size();i++){
            if(i%2==1 && s[i]=='1') sols++;
            if(i%2==0 && s[i]=='0') sols++;
        }
        return ans = min(ans,sols);
    }
};