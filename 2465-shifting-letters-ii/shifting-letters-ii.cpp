class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size(),ss=shifts.size();
        vector<int> change(n+1,0);//no right error
        for(int i=0;i<ss;i++){
            vector<int>& shift=shifts[i];
            int left=shift[0],right=shift[1]+1,type=shift[2]==1?1:-1;
            change[left]+=type; 
            change[right]-=type;
        }
        for(int i=1;i<n;i++){
            change[i]=change[i-1]+change[i];
        }
        for(int i=0; i<n; i++){
            char& c=s[i];
            c=(change[i]+c-'a')%26+'a';
            if (c<'a') c+=26; 
        }
        return s;
    }
};