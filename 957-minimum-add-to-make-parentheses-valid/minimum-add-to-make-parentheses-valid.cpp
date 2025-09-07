class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0,count=0;
        for(int i=0;i<s.size();i++){
            count+=s[i]=='('?1:-1;
            if(count<0){
                ans+=1;
                count++;
            }
        }
        return ans+count;
    }
};